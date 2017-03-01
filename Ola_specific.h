This function prints the keyboard at a particular starting position.
If that starting position is past the first 21 letters (I.E it 
goes past the first keyboard and into the second, it starts from there)

  clear_screen is necessary at the start to ensure that the password
  shows appropriately after deletes
  
  
                                                       




void print_keyboard(volatile int start)
	{
	//if start is greater then 21, jump ahead 18 spots
	//if greater then 42, jump ahead two spots
	clear_screen();
	int jump = start/21;
	int index = 0 + jump * 21;
	int row;
	int col;
	for(col = 0;col<7;col++)
		{
		for (row = 0; row < 3; row++)
			{
			if(index == 70)
				return;
			textbuffer[row][2*col] = keyboard[index];
			index++;
			print_password();
			}
		}
	}

//Calling this after every cursor move ensures that password updates 
//instantly

void clear_screen()
	{
	 display_string(0," ");
	 display_string(1," ");
	 display_string(2," ");
	 display_string(3," ");
	}


void print_password()
	{
	int i = 0;
	for(i; i < passwordLength;i++ )
		{
		textbuffer[3][i] = password[i];
		}
	}


//call this when switching to a new keyboard menu
//It puts the cursor at the right place

void reset_keyboard_cursor()
		{
		currentline = 0;
		currentcolumn = 1;
		textbuffer[0][1] = '*';
		
		}


//The default response is just to add the chosen index result to
//password


//currently deleting from the password is done just
//by reducing password length by 1, and then never reading 
//or returning beyond that point. This is done currently by pressing 
//the 70th index of the keyboard array. You can change it to use the first button instead


void navigate_keyboard()
	{
	switch(keyboard_index)
		{
		case 69:
			{
			submit_password();
			}
		case 70:
			{

			passwordLength--;
			}
		default:
			{
			password[passwordLength] = keyboard[keyboard_index];
			passwordLength++;
			print_password();
			}
		}
	}

//currently deleting from the password is done just
//by reducing password length by 1, and then never reading 
//or returning beyond that point. This is done currently by pressing 
//the 70th index of the keyboard array. You can change it to use the first button instead







void send_menu(char** menuStrings, int numberOfStrings);

//Remember that this function's first parameter will now ften call an array that is
//pre built and stored in data.c, just like icon and font are also stored there.
//The rest of the time, it will call menus that the ESP specific functions
//have built and returned.
//I think it might be best to define, for each menu stored in data, a corresponding length as well
//This way, the average set menu when we navigate would be
// " void set_menu(home_menu, home_menu_length); "
//and when you build a menu (say, the wifi network list the ESP will fetch)
// you first build the array, keeping track of it's length, then pass both to the set_menu function
//Also, remember that it will be called set_menu in the end. 


void put_keyboard_cursor(int index);
//Often when we're moving up and down, this function is called with
//a parameter of "currentline + 1" or "currentline - 1";


void put_menu_cursor_at(int index)
//Same thing as above, but this function doesn't have to worry about current column
//Currently, it always uses column 13.
//It already handles roll over of menu printing


void display_string_at_bottom(char* passwordString);
//This was the original design in the google drive. I can't remember if we decided if
//the password would be stored as a global variable.
//If it were, this function would not need the char parameter, and could just reference
//the variable directly.

void lcd_init(void);
//This was in the google drive, but near as I can tell all of the work
//it should do is taken care of already elsewhere

