#ifndef USART_HEADER
#define USART_HEADER

#include <stdint.h>
#define USART2_ADDRESS ((usart *)0x40004400)

#define USART_BAUDRATE 115200U
#define USART_TRANSMIT_BUFFER_SIZE 100U

#define USART_CR1_UE (1U << 13)
#define USART_CR1_RXNEIE (1U << 5)
#define USART_CR1_TXEIE (1U << 7)
#define USART_CR1_TE (1U << 3)
#define USART_CR1_RE (1U << 2)

#define USART_SR_RXNE (1U << 5)
#define USART_SR_TC (1U << 6)
#define USART_SR_TXE (1U << 7)

struct usart_read_buffer{
    volatile uint8_t *buffer;
    uint32_t read_index;
    uint32_t size;
} typedef usart_read_buffer;

struct usart{
    volatile uint32_t SR, DR, BRR, CR1, CR2, CR3, GTPR;
} typedef usart;

void usart_config(usart *usart_p, uint32_t baudrate);
void usart_receive_interrupt(usart *usart_p, uint8_t *buffer, uint32_t buffer_size);
#endif