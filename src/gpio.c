#include <stdint.h>
#include <gpio.h>

void gpio_config(gpio *gpio_port, uint8_t pin, uint8_t mode){
    gpio_port->MODER &= ~(3U << (pin * 2));
    gpio_port->MODER |= mode << (pin * 2);
}
void gpio_write_pin(gpio *gpio_port, uint8_t pin, uint8_t val){
    uint32_t addr = val ? pin : pin+16;
    gpio_port->BSRR |= (1U << addr);
}
void gpio_set_alternate_function(gpio *gpio_port, uint8_t pin, uint8_t af){
    if(pin <= 7){
        gpio_port->AFRL &= ~(15U << (pin * 4));
        gpio_port->AFRL |= af << (pin * 4);
    }
    else if(pin > 7 && pin <= 15){
        gpio_port->AFRH &= ~(15U << ((pin - 8) * 4));
        gpio_port->AFRH |= af << ((pin - 8) * 4);
    }
}