#include <usart.h>
#include <gpio.h>
#include <config.h>
#include <math.h>
#include <nvic.h>

usart_read_buffer usart2_read_buffer;

void usart_config(usart *usart_p, uint32_t baudrate){
    if(usart_p == USART2_ADDRESS){
        // Configuring GPIO Pins
        gpio_config(GPIO_GPIOA, 2, GPIO_MODE_AF);
        gpio_set_alternate_function(GPIO_GPIOA, 2, GPIO_AF7);
        gpio_config(GPIO_GPIOA, 3, GPIO_MODE_AF);
        gpio_set_alternate_function(GPIO_GPIOA, 3, GPIO_AF7);        
        // Enable USART
        usart_p->CR1 |= USART_CR1_UE;
        // Set baudrate
        float usartdiv = CLOCK_FREQ / (16.0f * baudrate);
        uint16_t div_mantissa = ((uint16_t)floorf(usartdiv));
        uint8_t div_fraction = ((uint8_t)roundf((usartdiv - div_mantissa) * 16));
        div_mantissa += div_fraction > 15 ? 1 : 0;
        usart_p->BRR = (div_mantissa << 4) | div_fraction;
        // Enable transmitter
        usart_p->CR1 |= USART_CR1_TE;
        // Enable receiver
        usart_p->CR1 |= USART_CR1_RE;
        // NVIC Enable USART2_IRQHandler
        nvic_enable_IRQ(NVIC_USART2);
    }
}
void usart_receive_interrupt(usart *usart_p, uint8_t *buffer, uint32_t buffer_size){
    usart_p->CR1 |= USART_CR1_RXNEIE;
    if (usart_p == USART2_ADDRESS)
    {
        usart2_read_buffer.buffer = buffer;
        usart2_read_buffer.write_index = 0;
        usart2_read_buffer.read_index = 0;
        usart2_read_buffer.symbols_to_read = 0;
        usart2_read_buffer.size = buffer_size;
    }    
}
uint8_t usart_read_from_buffer(usart *usart_p){
    uint8_t result = '\0';
    if (usart_p == USART2_ADDRESS)
    {   
        while (usart2_read_buffer.symbols_to_read == 0){}        
        result = usart2_read_buffer.buffer[usart2_read_buffer.read_index];
        usart2_read_buffer.read_index = (usart2_read_buffer.read_index + 1) % usart2_read_buffer.size;
        usart2_read_buffer.symbols_to_read--;
    }
    return result;
}
// Interrupt Service Routines
void USART2_IRQHandler(void){
    usart *usart2 = USART2_ADDRESS;
    if (usart2->SR & USART_SR_RXNE)
    {
        usart2_read_buffer.buffer[usart2_read_buffer.write_index] = usart2->DR;
        usart2_read_buffer.write_index = (usart2_read_buffer.write_index + 1) % usart2_read_buffer.size;
        usart2_read_buffer.symbols_to_read = (usart2_read_buffer.symbols_to_read < usart2_read_buffer.size) ? usart2_read_buffer.symbols_to_read + 1 : usart2_read_buffer.size;
    }    
}