/* mipslabwork.c

   This file written 2015 by F Lundevall

   This file should be changed by YOU! So add something here:

   This file modified 2015-12-24 by Ture Teknolog

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */
#include <stdio.h>
#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "master.h"  /* Declatations for these labs */
extern char* home_menu[];
extern int home_menu_length;
extern char* cities_menu[];
extern int cities_menu_length;
extern char* wifi_menu[] ;
extern int wifi_menu_length;

	//Store all the menus as data objects elsewhere
	//for navigate keyboard
		//during a button processButtons
			//calculate which type ofk eyboard
				//default, dispatch to password the value of currentcolumna nd currentline transformed into an appropriate value
					//two special cases, back and forwards




int timeoutcount = 0; // global counter
volatile int currentline = 0;
volatile int currentcolumn = 13;

volatile char display_type = 'm';
//volatile char password[];
volatile int currentmenulength = 4;
char * menu[10];
//char** menu2;



//Write a wifi network ESP request into menu_navigation
//Write a keyboard print function
//Write a keyboard select function
//Write a wifi array building function and print it for arbitrary lengths
//keyboard column navigate
//city request ascii construction
//city info display
//





		void navigate()
			{if(*menu == *home_menu)
				switch(currentline)
				 {
				
					 // home menu options *************************************
				 case 0:
					 {
					 set_menu(cities_menu,cities_menu_length);
					 clear_screen();
					 print_menu(0);
					 reset_menu_cursor();
					 return;
					 }
				 case 1:
					 {
					 set_menu(wifi_menu,wifi_menu_length);
					 clear_screen();
					 print_menu(0);
					 reset_menu_cursor();
					 return;
					 }
				 case 2:
					 {
					 set_menu(home_menu,home_menu_length);
					 clear_screen();
					 print_menu(0);
					 reset_menu_cursor();
					 return;
					 }
				 case 3:
					 {
					 set_menu(home_menu,home_menu_length);
					 clear_screen();
					 print_menu(0);
					 reset_menu_cursor();
					 return;
					 }
				 }

				else if(*menu == *cities_menu)
				{

				switch(currentline)
					 {// City menu options ************************************
					 case 0:
						 {
						 set_menu(cities_menu,cities_menu_length);
						 clear_screen();
						 print_menu(0);
						 reset_menu_cursor();
						 return;
						 }
						 
					case 1:
						{
						 set_menu(cities_menu,cities_menu_length);
						 clear_screen();
						 print_menu(0);
						 reset_menu_cursor();
						}
						
					case 2:
						{
						 set_menu(cities_menu,cities_menu_length);
						 clear_screen();
						 print_menu(0);
						 reset_menu_cursor();
						}
						
					case 3:
						{
						set_menu(home_menu,home_menu_length);//back function
						clear_screen();
						print_menu(0);
						reset_menu_cursor();
							
						return;
						}
					}
				}
			else if(*menu == *wifi_menu)
				{
					// Wifi menu options **************************************
				switch(currentline)
					{
						case 0:
							{
						
							ESP_Return_Networks();
							clear_screen();
							print_menu(0);
							reset_menu_cursor();
							return;
							}
						case 1:
							{
							clear_screen();	
							print_menu(0);
							reset_menu_cursor();
							return;
							}
						case 2:
							{
							set_menu(home_menu,home_menu_length);
							print_menu(0);
							reset_menu_cursor();
							
							return;
							}
						case 3:
							{
							set_menu(home_menu,home_menu_length);
							print_menu(0);
							reset_menu_cursor();
						
							return;
							}
						}
					}


			return;
			}
			
			
			

					void processButtons(int buttonPress)
						{
						if(display_type == 'm')
							{
								if(buttonPress & 0x4)// Button 4
									{
									navigate();
									}
							if(buttonPress & 0x2) // button 2
								  {
									put_menu_cursor_at(currentline + 1);
						 			}
							if(buttonPress & 0x1) // button 1
									{
									put_menu_cursor_at(currentline -1);
									}
							}
							else if(display_type == 'k')
								{
									if(buttonPress & 0x4)// Button 4
										{

								   	navigate_keyboard();
										}
								if(buttonPress & 0x2) // button 2
									  {
										//move_keyboard_cursor(1);
							 			}
								if(buttonPress & 0x1) // button 1
										{
										//move_keyboard_cursor(-1);
										}
								}
							}
	// void move_keyboard_cursor(int index)
	// 		{
	// 		textbuffer[currentline][currentcolumn] = ' ';
	// 		if((direction + currentline) == 4)
	// 			currentcolumn = mod(currentcolumn + 2,14);
	// 		else if((direction + currentline) == -1)
	// 			currentcolumn = mod(currentcolumn - 2, 14);
	//
	// 		currentline = mod(currentline+direction,4);
	// 		textbuffer[currentline][currentcolumn] = '*';
	// 		return;
	// 		}



void set_menu(char** new_menu, int menu_length)
	{
	currentmenulength = menu_length;
	int i = 0;
	for(i; i < currentmenulength;i++)
		{
		menu[i] = new_menu[i];	
		}
	 
	}

void put_menu_cursor_at(int index)
	{
	textbuffer[mod(currentline,4)][13] = ' ';
	currentline = mod(index,currentmenulength);
	print_menu(currentline);
	textbuffer[mod(currentline,4)][13] = '*';
	}


void reset_menu_cursor()
		{
		currentline = 0;
		currentcolumn = 13;
		textbuffer[currentline][currentcolumn] = ' ';
		textbuffer[0][13] = '*';
		}

void reset_keyboard_cursor()
		{
		currentline = 0;
		currentcolumn = 1;
		textbuffer[currentline][currentcolumn] = ' ';
		textbuffer[0][1] = '*';
		}

void navigate_keyboard( )
		{
		return;
		}
void clear_screen()
	{
	 display_string(0," ");
	 display_string(1," ");
	 display_string(2," ");
	 display_string(3," ");
	}
void print_menu(int start)
	{
	clear_screen();
	int jump = start/4;
	int i = 0 + 4*jump;
	int j = 0;
	for(j; j < 4; j++)
		{
		if(i >=  currentmenulength)
			return;
		display_string(j, menu[i]);
		i++;
		}
	}

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
	  
	set_menu(home_menu,home_menu_length);
	print_menu(0); //Displays initial options
	
	
	textbuffer[0][13] = '*';
	}
					
					
void ESP_Return_Networks()
	{
	char* new_menu[10] ;
	new_menu[0] = "network";
	new_menu[1] = "second";
	new_menu[2] = "Ola   ";
	new_menu[3] = "smells";
	new_menu[4] = "TESTING";
	new_menu[5] = "Is this";
	new_menu[6] = "thing on?";
	new_menu[7] = "Helllooo?";
	new_menu[8] = "Finally";
	int length = 9;
	set_menu(new_menu,9);
	}
	
	
	
	
	
void user_isr( void )
{

  if((IFS(0) & 0x100) == 0x100)
	{
	TMR2 = 0x0; // Clear timer register
	IFS(0) = IFS(0) & 0xfffffeff; // reset event flag
	timeoutcount++;
  	}

  if(timeoutcount == 3)
	{ // execute display/time functions after count reaches 10
	//PORTE = currentmenu;
	timeoutcount = 0;
	int btnpress = getbtns();
	processButtons(btnpress);
	}

}



/* This function is called repetitively from the main program */
void loop( void )
	{
	display_update();
	}


