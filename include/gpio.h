#ifndef GPIO_HEADER
#define GPIO_HEADER

#define GPIO_GPIOA ((gpio *)0x40020000U)

#define GPIO_MODE_INPUT 0U
#define GPIO_MODE_OUTPUT 1U
#define GPIO_MODE_AF 2U
#define GPIO_MODE_ANALOG 3U

#define GPIO_AF0 0U
#define GPIO_AF1 1U
#define GPIO_AF2 2U
#define GPIO_AF3 3U
#define GPIO_AF4 4U
#define GPIO_AF5 5U
#define GPIO_AF6 6U
#define GPIO_AF7 7U
#define GPIO_AF8 8U
#define GPIO_AF9 9U
#define GPIO_AF10 10U
#define GPIO_AF11 11U
#define GPIO_AF12 12U
#define GPIO_AF13 13U
#define GPIO_AF14 14U
#define GPIO_AF15 15U

#define GPIO_RESET 0
#define GPIO_SET 1

struct gpio{
  volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFRL, AFRH;
} typedef gpio;

void gpio_config(gpio *gpio_port, uint8_t pin, uint8_t mode);
void gpio_write_pin(gpio *gpio_port, uint8_t pin, uint8_t val);
void gpio_set_alternate_function(gpio *gpio_port, uint8_t pin, uint8_t af);

#endif
