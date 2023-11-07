#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emscripten.h"


// emcc control.c -g -o control.js -sEXPORTED_FUNCTIONS=_main,_register_basic_customer -sEXPORTED_RUNTIME_METHODS=ccall,cwrap


// A struct with a string and function pointer member
typedef struct {
    char name[32];
    void (*greeting) (char*);
} Greeting;


// Two greeting functions that write a string to the DOM based on the user's subscription
// Note that the XSS doesn't happen in these functions even though they are writing to the DOM.
// In fact, these functions are never even called if the table index is overwritten.
void basic_greeting(char* name) {
    EM_ASM({
        document.getElementById("output").innerHTML = "Hello " + $0+ "!";
    }, name);
}
void premium_greeting(char* name) {
    EM_ASM({
        document.getElementById("output").innerHTML = "My deepest gratitude to you, " + $0;
    }, name);
}

// Vulnerable function
void register_basic_customer(char* newName) {
   
    // Allocate structure on stack (or heap, works either way)
    Greeting G = {"New Customer", &basic_greeting};

    // Buffer overflow
    strcpy(G.name, newName);

    printf("Struct          : %p\n", &G);
    printf("Function pointer: %p\n", &G.greeting);

    // Greet the new customer
    G.greeting(G.name);
}



int main(){
    // Fill up function table so that index of emscripten_run_script is 10,
    // which is the smallest ASCII value that can be entered into a form (\n character)
    printf("malloc               : %p\n", &malloc);
    printf("calloc               : %p\n", &calloc);
    printf("strcpy               : %p\n", &strcpy);
    printf("memcpy               : %p\n", &memcpy);
    printf("printf               : %p\n", &printf);
    printf("strncpy              : %p\n", &strncpy);
    printf("strlen               : %p\n", &strlen);
    printf("strstr               : %p\n", &strstr);
    printf("strtok               : %p\n", &strtok);
    printf("emscripten_run_script: %p\n", &emscripten_run_script);

    return 0;
}