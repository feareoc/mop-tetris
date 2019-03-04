/*
 * 	startup.c
 *
 */
void startup(void) __attribute__((naked)) __attribute__((section (".start_section")) );

/**
 * Grafik
 * Ascii
 * Keyboard
 * Delay
 */
 
void startup ( void )
{
asm volatile(
	" LDR R0,=0x2001C000\n"		/* set stack */
	" MOV SP,R0\n"
	" BL main\n"				/* call main */
	".L1: B .L1\n"				/* never return */
	) ;
}

#include "graphics.h"
#include "keyboard.h"

void app_init()
{
    keyb_init();
    graphic_init();
    //graphic_clear_screen();
    //ascii_init();
}

int main()
{
    app_init();
    
    while (1)
    {
        graphic_swap();
    }
}

