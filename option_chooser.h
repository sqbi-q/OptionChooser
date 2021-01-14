#define call_func(x) ((void(*)())x)();
#define MAX_MENUS_COUNT 100

extern int _PREV_CURR_MENU_INDEX;
extern int _CURRENT_MENU_INDEX;
extern int _MENUS_COUNT;

/*
Option in menu structure
*/
struct option_t {
    char* name;
    char* desc;
    void* func_ptr;
};

/*
Menu structure
*/
typedef struct menu_t {
    char* id;
    unsigned int count;
    struct option_t* options;
} menu_t;

// //init option chooser
// void init_option_chooser();

//Menus list
extern menu_t _ALL_MENUS_LIST[MAX_MENUS_COUNT];

//initialize menu
menu_t init_menu(char* id, unsigned int count, ...);

//initialize option
struct option_t init_option(char* name, char* desc, void* func_ptr);

//printf all options of menu
void show_options(menu_t menu);

//show current menu's all options
void show_current_options();

//get input from user
int get_respone(char* str);

//select n-th option of current menu
void run_option(int n); 

//change to N-th menu
void set_current_menu(int n);

//iterate to another menu
void set_next_menu();

//set current menu as previous current menu (return to previous menu)
void set_previous_menu();

//get index of menu with specified id
int get_menu_index_by_id(char* id);

//set current menu with specified id
void set_curr_menu_by_id(char* id);