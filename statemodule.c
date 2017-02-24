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

int timeoutcount = 0; // global counter
volatile int currentline = 0;
volatile int currentcolumn = 13;
volatile int currentmenu = 0;
volatile char display_type = 'm';
//volatile char password[];
volatile int currentmenulength = 7;
char *menu[10];
//char** menu2;
char* menu2[4];
char* str0 = "good point";
char* str1 = "goodbye";
char* str2 = "fuck off";
char* str3 = "raaaghhhh";
char* str4 = "second";
char* str5 = "menu";
char* str6 = "here";
// currentmenu = &menu;
/* Interrupt Service Routine */

//Write a wifi network ESP request into menu_navigation
//Write a keyboard print function
//Write a keyboard select function
//Write a wifi array building function and print it for arbitrary lengths
//

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
		PORTE = currentmenu;
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





		void navigate()
			{if(currentmenu == 0)
				switch(currentline)
				 {

					 // home menu options *************************************
				 case 0:
					 {
					 display_menu(1);
					 reset_menu_cursor(currentline, currentcolumn);
					 currentmenu = 1;
					 return;
					 }
				 case 1:
					 {
					 currentmenu = 2;
					 display_menu(2);
					 reset_menu_cursor(currentline, currentcolumn);
					 return;
					 }
				 case 2:
					 {
					 currentmenu = 0;
					 display_menu(0);
 			   	 reset_menu_cursor(currentline, currentcolumn);
					 return;
					 }
				 case 3:
					 {
					 currentmenu = 0;
					 display_menu(0);
					 reset_menu_cursor(currentline, currentcolumn);
					 return;
					 }
				 }

				else if(currentmenu == 1)
				{

				switch(currentline)
					 	{// City menu options ************************************
					 case 0:
						 {
						 display_menu(1);//Unimplemented
						 reset_menu_cursor(currentline, currentcolumn);
						 currentmenu = 1;
						 return;
						 }
						case 1:
							{
							 display_menu(1);//Unimplemented
							 reset_menu_cursor(currentline, currentcolumn);
							 currentmenu = 1;
							 return;
							}
						case 2:
							{
							 display_menu(1);//Unimplemented
							 reset_menu_cursor(currentline, currentcolumn);
							 currentmenu = 1;
							 return;
							}
						case 3:
							{
							 display_menu(0);//back function
							 reset_menu_cursor(currentline, currentcolumn);
							 currentmenu = 0;
							 return;
							}
						}
				}
			else if(currentmenu == 2)
				{
					// Wifi menu options **************************************
				switch(currentline)
					{
						case 0:
							{

							ESP_Return_Networks();
							print_menu(6);
							reset_menu_cursor(currentline,currentcolumn);
							currentmenu = 5;
							return;
							}
						case 1:
							{
							display_menu(2);//Unimplemented
							reset_menu_cursor(currentline, currentcolumn);
							currentmenu = 2;
							return;
							}
						case 2:
							{
							display_menu(2);//Unimplemented
							reset_menu_cursor(currentline, currentcolumn);
							currentmenu = 2;
							return;
							}
						case 3:
							{
							display_menu(0);//back function
							reset_menu_cursor(currentline, currentcolumn);
							currentmenu = 0;
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
										put_keyboard_cursor(currentline + 1);
							 			}
								if(buttonPress & 0x1) // button 1
										{
										put_keyboard_cursor(currentline - 1);
										}
								}
							}
	void put_keyboard_cursor(int index)
			{
			textbuffer[currentline][currentcolumn] = ' ';
			if() == 4)
				{currentcolumn = mod(currentcolumn + 2,14);}
			else if(index == 0)
			currentline = mod(index,currentmenulength);
			print_menu(currentline);
			if((direction + currentline) == 4)
				currentcolumn = mod(currentcolumn + 2,14);
			else if((direction + currentline) == -1)
				currentcolumn = mod(currentcolumn - 2, 14);

			currentline = mod(currentline+direction,4);
			textbuffer[currentline][currentcolumn] = '*';
			return;
			}


					void put_menu_cursor_at(int index)
						{
						textbuffer[mod(currentline,4)][13] = ' ';

						currentline = mod(index,currentmenulength);
						print_menu(currentline);
						textbuffer[mod(currentline,4)][13] = '*';
						}

// void test_menu(char** menu2)
// 	{
// 	display_string(0,menu2[0]);
// 	display_string(1,"hello");
// 	display_string(2,menu2[1]);
// 	}


char** set_menu()
	{
	//char** menuStrings;
	/*char str0 = "good point";
	char str1 = "goodbye";
	char str2 = "fuck off";
	char str3 = "raaaghhhh";*/
	menu[0] = str0;
	menu[1] = str1;
	menu[2] = str2;
	menu[3] = str3;
	menu[4] = "second";
	menu[5]= "menu";
	menu[6] = "here";
	return menu;
	//menu2 = *menuStrings;
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

void print_menu(int start)
	{
	int jump = start/4;
	int i = 0 + 4*jump;
	int j = 0;
	for(j; j < 4; j++)
		{
		if(i >=  currentmenulength)
			display_string(j," ");
		else
			display_string(j, menu[i]);
		i++;
		}
	}

	//Store all the menus as data objects elsewhere
	//for navigate keyboard
		//during a button processButtons
			//calculate which type ofk eyboard
				//default, dispatch to password the value of currentcolumna nd currentline transformed into an appropriate value
					//two special cases, back and forwards

void ESP_Return_Networks()
	{

	menu[0] = "network";
	menu[1] = "second";
	menu[2] = "Ola   ";
	menu[3] = "smells";
	menu[4] = "TESTING";
	menu[5] = "Is this";
	menu[6] = "thing on?";
	menu[7] = "Helllooo?";
	menu[8] = "Finally";
	currentmenulength = 9;
	}
