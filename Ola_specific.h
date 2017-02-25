void set_keyboard(char* keyboardChars, int numberOfChars);
//The first parameter will now be arrays of chars that are pre-built in data.c, just
//as icon and font are. Defining a variable for each keyboard for numberofChars will make life easier as well
//Generally then, a function call will look like 
// "set_keyboard(lower_case_chars, lower_Case_chars_length);"


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

