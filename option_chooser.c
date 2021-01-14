#include "option_chooser.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


int _CURRENT_MENU_INDEX = 0;
int _PREV_CURR_MENU_INDEX = 0;
int _MENUS_COUNT = 0;
menu_t _ALL_MENUS_LIST[MAX_MENUS_COUNT];

void _add_menu_to_list(menu_t menu){
    _ALL_MENUS_LIST[_MENUS_COUNT] = menu;
    _MENUS_COUNT += 1;
}

menu_t init_menu(char* id, unsigned int count, ...){
    menu_t menu;
    menu.id = id; 
    menu.count = count;


    menu.options = malloc(count*sizeof(struct option_t));
    

    va_list valist;
    va_start(valist, count);
    for (int i = 0; i < count; i++) {
        menu.options[i] = va_arg(valist, struct option_t);
    }
    va_end(valist);

    _add_menu_to_list(menu);
    return menu;
}

struct option_t init_option(char* name, char* desc, void* func_ptr){
    struct option_t option;
    option.name = name; 
    option.desc = desc;
    option.func_ptr = func_ptr;

    return option;
}

void show_options(menu_t menu){
    for(int i=0; i<menu.count; i++){
        printf("%d) %s\n", i, menu.options[i].name);
    }
}

void show_current_options(){
    show_options(_ALL_MENUS_LIST[_CURRENT_MENU_INDEX]);
}

int get_respone(char* str){
    int respone = -1;
    printf("%s", str);
    scanf("%d", &respone);
    return respone;
}

void run_option(int n){
    call_func(_ALL_MENUS_LIST[_CURRENT_MENU_INDEX].options[n].func_ptr);
}

void set_current_menu(int n){
    _PREV_CURR_MENU_INDEX = _CURRENT_MENU_INDEX;
    _CURRENT_MENU_INDEX = n;
}

void set_next_menu(){
    set_current_menu(_CURRENT_MENU_INDEX+1);
}

void set_previous_menu(){
    set_current_menu(_PREV_CURR_MENU_INDEX);
}

int get_menu_index_by_id(char* id){
    for(int i=0; i<_MENUS_COUNT; i++){
        if (strcmp(_ALL_MENUS_LIST[i].id, id) == 0) return i;
    }
    return -1;
}

void set_curr_menu_by_id(char* id){
    int index = get_menu_index_by_id(id);
    set_current_menu(index);
}