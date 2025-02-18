#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "pico/bootrom.h"

#include "buzzer.h"

#define FREQUENCY 1000  

uint8_t leds_rgb[3] = {11, 12, 13};
uint8_t buzzer_pin = 21;


void inicializa_leds() {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_init(leds_rgb[i]);
        gpio_set_dir(leds_rgb[i], GPIO_OUT);
        gpio_put(leds_rgb[i], 0); 
    }
}


void liga_led(uint8_t led) {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_put(leds_rgb[i], leds_rgb[i] == led ? 1 : 0);
    }
}


void liga_todos_leds() {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_put(leds_rgb[i], 1);
    }
}


void desliga_todos_leds() {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_put(leds_rgb[i], 0);
    }
}


int main() {
    stdio_init_all();
    inicializa_leds();
    setup_buzzer(buzzer_pin, FREQUENCY);

    char comando;

    while (1) {
        comando = getchar();
        printf("Comando recebido: %c\n", comando);
        
        switch (comando)
        {
        case 'r':
            liga_led(13);
            printf("ON: RED\n");
            break;
        case 'g':
            liga_led(11);
            printf("ON: GREEN\n");
            break;
        case 'b':
            liga_led(12);
            printf("ON: BLUE\n");
            break;
        case 'w':
            liga_todos_leds();
            printf("ON: WHITE\n");
            break;
        case '0':
            desliga_todos_leds();
            printf("ON: --\n");
            break;
        case 'z':
            start_buzzer(buzzer_pin, FREQUENCY); // Liga o buzzer com a frequência definida
            sleep_ms(2000);                      // Mantém por 500ms
            stop_buzzer(buzzer_pin);
            printf("ON: BUZZER\n");
            break;
        case '1':
            reset_usb_boot(0, 0);
            break;
        
        default:
            printf("Invalid Input.\n");
            break;
        }

    }
    sleep_ms(100);
}
