#include <string.h>
#include <stdint.h>
#include <morse.h>
#include <gpio.h>
#include <systick.h>

void morse_send(uint8_t symbol){
    uint8_t msg[6];
    uint8_t current;
    switch (symbol){
        case 'a': case 'A':
            strncpy(msg, ".-", 6);
            break;
        case 'b': case 'B':
            strncpy(msg, "-...", 6);
            break; 
        case 'c': case 'C':
            strncpy(msg, "-.-.", 6);
            break;
        case 'd': case 'D':
            strncpy(msg, "-..", 6);
            break;
        case 'e': case 'E':
            strncpy(msg, ".", 6);
            break;
        case 'f': case 'F':
            strncpy(msg, "..-.", 6);
            break;
        case 'g': case 'G':
            strncpy(msg, "--.", 6);
            break;
        case 'h': case 'H':
            strncpy(msg, "....", 6);
            break;
        case 'i': case 'I':
            strncpy(msg, "..", 6);
            break;
        case 'j': case 'J':
            strncpy(msg, ".---", 6);
            break;
        case 'k': case 'K':
            strncpy(msg, "-.-", 6);
            break;
        case 'l': case 'L':
            strncpy(msg, ".-..", 6);
            break;
        case 'm': case 'M':
            strncpy(msg, "--", 6);
            break;
        case 'n': case 'N':
            strncpy(msg, "-.", 6);
            break;
        case 'o': case 'O':
            strncpy(msg, "---", 6);
            break;
        case 'p': case 'P':
            strncpy(msg, ".--.", 6);
            break;
        case 'q': case 'Q':
            strncpy(msg, "--.-", 6);
            break;
        case 'r': case 'R':
            strncpy(msg, ".-.", 6);
            break;
        case 's': case 'S':
            strncpy(msg, "...", 6);
            break;
        case 't': case 'T':
            strncpy(msg, "-", 6);
            break;
        case 'u': case 'U':
            strncpy(msg, "..-", 6);
            break;
        case 'v': case 'V':
            strncpy(msg, "...-", 6);
            break;
        case 'w': case 'W':
            strncpy(msg, ".--", 6);
            break;
        case 'x': case 'X':
            strncpy(msg, "-..-", 6);
            break;
        case 'y': case 'Y':
            strncpy(msg, "-.--", 6);
            break;
        case 'z': case 'Z':
            strncpy(msg, "--..", 6);
            break;
        case ' ':
            systick_delay(4 * MORSE_UNIT);
            break;
        default:
            return;
            break;
        }
    uint8_t *p = msg;
    while(*p != '\0'){
        if(*p == '.'){
            gpio_write_pin(GPIO_GPIOA, 5, GPIO_SET);
            systick_delay(MORSE_UNIT);
            gpio_write_pin(GPIO_GPIOA, 5, GPIO_RESET);
            systick_delay(MORSE_UNIT);
        }else if(*p == '-'){
            gpio_write_pin(GPIO_GPIOA, 5, GPIO_SET);
            systick_delay(3 * MORSE_UNIT);
            gpio_write_pin(GPIO_GPIOA, 5, GPIO_RESET);
            systick_delay(MORSE_UNIT);
        }
        p++;
    }
    systick_delay(2 * MORSE_UNIT);
}