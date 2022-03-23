
#include "stm8s.h"
#include "milis.h"
#include "stm8_hd44780.h"

//#include "delay.h"
#include <stdio.h>
//#include "uart1.h"

#define _ISOC99_SOURCE
#define _GNU_SOURCE

#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_4
#define LED_HIGH   GPIO_WriteHigh(LED_PORT, LED_PIN)
#define LED_LOW  GPIO_WriteLow(LED_PORT, LED_PIN)
#define LED_REVERSE GPIO_WriteReverse(LED_PORT, LED_PIN)



void setup(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_IN_PU_NO_IT); // nastavíme pin PG4 jako vstup s vnitřním pull-up rezistorem  v pospisech nesedi jmena pinu
    GPIO_Init(GPIOB,GPIO_PIN_4,GPIO_MODE_IN_PU_NO_IT); // nastavíme pin PG5 jako vstup s vnitřním pull-up rezistorem
    GPIO_Init(GPIOC,GPIO_PIN_3,GPIO_MODE_IN_PU_NO_IT); // nastavíme pin PG4 jako vstup s vnitřním pull-up rezistorem
    GPIO_Init(GPIOD,GPIO_PIN_3,GPIO_MODE_IN_PU_NO_IT); // nastavíme pin PG5 jako vstup s vnitřním pull-up rezistorem
    GPIO_Init(GPIOD,GPIO_PIN_2,GPIO_MODE_IN_PU_NO_IT); // nastavíme pin PG4 jako vstup s vnitřním pull-up rezistorem
 
    lcd_init(); //inicializace LCD
    init_milis();
    //init_uart1();
}


int main(void)
{
    //uint32_t time = 0;
    //uint32_t cum = 0;
    //char text[32];
    int h = 0;
    int m = 5;
    int s = 0;
    uint32_t pozice = 0; //vyjadřuje pozici měňění čísel 0 == h , 1 == m , 2 == s

    _Bool minuly_stav_on_tlacitka=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool minuly_stav_off_tlacitka=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool aktualni_stav_tlacitka=0; // 0=tlačítko je uvolněné, 1= tlačítko je stisknuté

    _Bool minuly_stav_on_tlacitka2=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool minuly_stav_off_tlacitka2=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool aktualni_stav_tlacitka2=0; // 0=tlačítko je uvolněné, 1= tlačítko je stisknuté

    _Bool minuly_stav_on_tlacitka3=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool minuly_stav_off_tlacitka3=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool aktualni_stav_tlacitka3=0; // 0=tlačítko je uvolněné, 1= tlačítko je stisknuté

    _Bool minuly_stav_on_tlacitka4=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool minuly_stav_off_tlacitka4=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool aktualni_stav_tlacitka4=0; // 0=tlačítko je uvolněné, 1= tlačítko je stisknuté

    _Bool minuly_stav_on_tlacitka5=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool minuly_stav_off_tlacitka5=0; // 0=tlačítko bylo minule uvolněné, 1=tlačítko bylo minule stisknuté 
    _Bool aktualni_stav_tlacitka5=0; // 0=tlačítko je uvolněné, 1= tlačítko je stisknuté
    

    setup();
    
    
    char text[16];
    lcd_gotoxy(0,1);
    sprintf(text, "cas: %02d:%02d:%02d", h, m, s);
    lcd_puts(text);
    

    while (1) {
 
        // tlacitko 1 ////////////////////////////////////////////////////////////////////////////////////////////////
        // zjistíme stav "ON" tlačítka
        if(GPIO_ReadInputPin(GPIOB,GPIO_PIN_5)==RESET){ // pokud je na vstupu od "ON" tlačítka log.0 tak...
        aktualni_stav_tlacitka=1; // ...je tlačítko stisknuté
        }
        else{ // jinak je ...
        aktualni_stav_tlacitka=0; // ...tlačítko uvolněné
        }
        // zjišťujeme jestli nastal "okamžik stisku"
        if(minuly_stav_on_tlacitka==0 && aktualni_stav_tlacitka==1){
        LED_REVERSE; // pokud ano, rozsvítíme LEDku
        lcd_gotoxy(0,0);
        lcd_puts("1");
        /*
        lcd_gotoxy(0, 1);
        sprintf(text,"cum ");
        lcd_puts(text);
        */
        }
        minuly_stav_on_tlacitka = aktualni_stav_tlacitka; // přepíšeme minulý stav tlačítka aktuálním

        // tlacitko 2 /////////////////////////////////////////////////////////////////////////////////////////////////////
        // zjistíme stav "ON" tlačítka
        if(GPIO_ReadInputPin(GPIOB,GPIO_PIN_4)==RESET){ // pokud je na vstupu od "ON" tlačítka log.0 tak...
        aktualni_stav_tlacitka2=1; // ...je tlačítko stisknuté
        }
        else{ // jinak je ...
        aktualni_stav_tlacitka2=0; // ...tlačítko uvolněné
        }
        // zjišťujeme jestli nastal "okamžik stisku"
        if(minuly_stav_on_tlacitka2==0 && aktualni_stav_tlacitka2==1){
        LED_REVERSE; // pokud ano, rozsvítíme LEDku
        lcd_gotoxy(0,0);
        lcd_puts("2");
        /*
        lcd_gotoxy(0, 1);
        sprintf(text,"cum ");
        lcd_puts(text);
        */
        }
        minuly_stav_on_tlacitka2 = aktualni_stav_tlacitka2; // přepíšeme minulý stav tlačítka aktuálním

        // tlacitko 3 /////////////////////////////////////////////////////////////////////////////////////////////////////
        // zjistíme stav "ON" tlačítka
        if(GPIO_ReadInputPin(GPIOC,GPIO_PIN_3)==RESET){ // pokud je na vstupu od "ON" tlačítka log.0 tak...
        aktualni_stav_tlacitka3=1; // ...je tlačítko stisknuté
        }
        else{ // jinak je ...
        aktualni_stav_tlacitka3=0; // ...tlačítko uvolněné
        }
        // zjišťujeme jestli nastal "okamžik stisku"
        if(minuly_stav_on_tlacitka3==0 && aktualni_stav_tlacitka3==1){
        LED_REVERSE; // pokud ano, rozsvítíme LEDku
        lcd_gotoxy(0,0);
        lcd_puts("3");
        /*
        lcd_gotoxy(0, 1);
        sprintf(text,"cum ");
        lcd_puts(text);
        */
        }
        minuly_stav_on_tlacitka3 = aktualni_stav_tlacitka3; // přepíšeme minulý stav tlačítka aktuálním

        // tlacitko 4 /////////////////////////////////////////////////////////////////////////////////////////////////////
        // zjistíme stav "ON" tlačítka
        if(GPIO_ReadInputPin(GPIOD,GPIO_PIN_2)==RESET){ // pokud je na vstupu od "ON" tlačítka log.0 tak...
        aktualni_stav_tlacitka4=1; // ...je tlačítko stisknuté
        }
        else{ // jinak je ...
        aktualni_stav_tlacitka4=0; // ...tlačítko uvolněné
        }
        // zjišťujeme jestli nastal "okamžik stisku"
        if(minuly_stav_on_tlacitka4==0 && aktualni_stav_tlacitka4==1){
        LED_REVERSE; // pokud ano, rozsvítíme LEDku
        lcd_gotoxy(0,0);
        lcd_puts("4");
        /*
        lcd_gotoxy(0, 1);
        sprintf(text,"cum ");
        lcd_puts(text);
        */
        }
        minuly_stav_on_tlacitka4 = aktualni_stav_tlacitka4; // přepíšeme minulý stav tlačítka aktuálním

        // tlacitko 5 /////////////////////////////////////////////////////////////////////////////////////////////////////
        // zjistíme stav "ON" tlačítka
        if(GPIO_ReadInputPin(GPIOD,GPIO_PIN_3)==RESET){ // pokud je na vstupu od "ON" tlačítka log.0 tak...
        aktualni_stav_tlacitka5=1; // ...je tlačítko stisknuté
        }
        else{ // jinak je ...
        aktualni_stav_tlacitka5=0; // ...tlačítko uvolněné
        }
        // zjišťujeme jestli nastal "okamžik stisku"
        if(minuly_stav_on_tlacitka5==0 && aktualni_stav_tlacitka5==1){
        LED_REVERSE; // pokud ano, rozsvítíme LEDku
        lcd_gotoxy(0,0);
        lcd_puts("5");
        /*
        lcd_gotoxy(0, 1);
        sprintf(text,"cum ");
        lcd_puts(text);
        */
        }
        minuly_stav_on_tlacitka5 = aktualni_stav_tlacitka5; // přepíšeme minulý stav tlačítka aktuálním












        //LED_REVERSE; 
        //delay_ms(333);
        //printf("Funguje to!!!\n");
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
