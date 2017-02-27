/* mipslab.h
   Header file for all labs.
   This file written 2015 by F Lundevall
   Some parts are original code written by Axel Isaksson

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */




/* Declare menu navigation functions from menu_navigate.c*/
void reset_menu_cursor();
void reset_keyboard_cursor();
void processButtons(int buttonPress);
void navigate();
//void select_line(int currentline, volatile int *currentmenu, volatile int *currentcolumn,volatile char* display_type);
void put_menu_cursor_at(int index);
void display_keyboard();
void send_menu();
void navigate_keyboard();
void move_keyboard_cursor(int direction);
/* Declare display-related functions from mipslabfunc.c */
void move_cursor(int direction);
void display_menu(char* menu[],int select);
void display_image(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
void print_menu();
uint8_t spi_send_recv(uint8_t data);
void display_debug( volatile int * const addr );
void print_array();
void print_menu(int start);
void checkforpageroll();
void set_menu(char** new_menu, int menu_length);
//Dummy functions
void ESP_Return_Networks();
void test_menu(char** menu);
void clear_screen();
/* Declare display_debug - a function to help debugging.

   After calling display_debug,
   the two middle lines of the display show
   an address and its current contents.

   There's one parameter: the address to read and display.

   Note: When you use this function, you should comment out any
   repeated calls to display_image; display_image overwrites
   about half of the digits shown by display_debug.
*/



/* Declare lab-related functions from mipslabfunc.c */
char * itoaconv( int num );
void initialize(void);
void loop(void);
int mod (int a, int b);



/* Declare bitmap array containing font */
extern const uint8_t const font[128*8];
/* Declare bitmap array containing icon */
extern const uint8_t const icon[128];
/* Declare text buffer for display output */
extern char textbuffer[4][16];

/* Written as part of asm lab: delay, time2string */


/* I/O functions. */
int getbtns(void);
int getsw(void);
