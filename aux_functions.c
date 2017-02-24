#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "master.h"  /* Declatations for these labs */





/* Lab-specific initialization goes here */
void initialize( void )
	{
  TRISE = TRISE & ~0xff; // set LEDs to output (initialize 8 lsb of Port E to outputs)
  TRISD = TRISD | ~0xffffe01f; // set bits 11 through 5 of Port D as inputs


  T2CON = 0x70; // set prescale for timer to 1:256
  TMR2 = 0x0; // Clear timer register
  PR2 = 31250; // Load period register (80 mHz/256/10 = 31,250)

  IPC(2) = IPC(2) | 0x1C; // set highest priority (7)
  IPC(2) = IPC(2) | 0x3; // set highest subpriority (3)
  enable_interrupt(); // enable global interrupts
  IEC(0) = IEC(0) | 0x100; // enable Timer 2 interrupt

  T2CON = T2CON | 0x8000; // Start timer
	char** menu;
	display_menu(0); //Displays initial options
	menu = set_menu();
	print_menu(5);
	textbuffer[0][13] = '*';
	}




int mod (int a, int b)


	{
   int ret = a % b;

   if(ret < 0)
	   {
     ret+=b;
	   }
   return ret;
	}
