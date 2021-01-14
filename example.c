#include "option_chooser.h"
#include <stdlib.h>
#include <stdio.h>

void _show_test_message_option(){
    printf("This is test message that should show up, when selecting first option of example menu.\n\nEnjoy!\n");
}

void _find_menu(){
    
}

int main(){
    init_menu("main_menu", 3, 
        init_option("Show test message", "This option should show example message.", &_show_test_message_option),
        init_option("Another menu", "Menu about...?", &set_next_menu),
        init_option("Exit", "Exit program", &exit)
    );

    init_menu("another_menu", 2,
        init_option("Find menu by id...", "Set current menu as menu found with id provided by user.", &_find_menu),
        init_option("Return", "Return to previous menu", &set_previous_menu)
    );
    
    int chosen_option = 0;
    while(1){

        show_current_options();
        chosen_option = get_respone("Choose index> ");
        run_option(chosen_option);

    }

    return 0;
}