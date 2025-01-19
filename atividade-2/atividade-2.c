#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

uint8_t leds_rgb[3] = {11, 12, 13};
uint8_t buzzer_pin = 27;

void inicializa_leds()
{
    for (uint8_t i = 0; i < 3; i++)
    {
        gpio_init(leds_rgb[i]);
        gpio_set_dir(leds_rgb[i], GPIO_OUT);
        gpio_put(leds_rgb[i], 0); // LEDs desligados inicialmente
    }
}

void inicializa_buzzer()
{
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);
    gpio_put(buzzer_pin, 0);
}

void liga_led(uint8_t led)
{
    for (uint8_t i = 0; i < 3; i++)
    {
        gpio_put(leds_rgb[i], leds_rgb[i] == led ? 1 : 0);
    }
}

void liga_todos_leds()
{
    for (uint8_t i = 0; i < 3; i++)
    {
        gpio_put(leds_rgb[i], 1);
    }
}

void desliga_todos_leds()
{
    for (uint8_t i = 0; i < 3; i++)
    {
        gpio_put(leds_rgb[i], 0);
    }
}

void liga_buzzer()
{
    gpio_put(buzzer_pin, 1);
    sleep_ms(2000);
    gpio_put(buzzer_pin, 0);
}

int main()
{
    stdio_init_all();
    inicializa_leds();
    inicializa_buzzer();

    printf("Sistema iniciado. Comandos disponíveis:\n");
    printf("  red    - Liga o LED vermelho\n");
    printf("  green  - Liga o LED verde\n");
    printf("  blue   - Liga o LED azul\n");
    printf("  white  - Liga todos os LEDs (luz branca)\n");
    printf("  off    - Desliga todos os LEDs\n");
    printf("  buzzer - Aciona o buzzer por 2 segundos\n");

    char comando[16];

    while (1)
    {
        if (fgets(comando, sizeof(comando), stdin))
        {
            comando[strcspn(comando, "\n")] = 0;

            printf("Comando recebido: %s\n", comando);

            if (strcmp(comando, "red") == 0)
            {
                liga_led(13);
            }
            else if (strcmp(comando, "green") == 0)
            {
                liga_led(11);
            }
            else if (strcmp(comando, "blue") == 0)
            {
                liga_led(12);
            }
            else if (strcmp(comando, "white") == 0)
            {
                liga_todos_leds();
            }
            else if (strcmp(comando, "off") == 0)
            {
                desliga_todos_leds();
            }
            else if (strcmp(comando, "buzzer") == 0)
            {
                liga_buzzer();
            }
            else
            {
                printf("Comando nao reconhecido.\n");
            }
        }
        sleep_ms(100); // Evitar uso excessivo de CPU
    }
}
