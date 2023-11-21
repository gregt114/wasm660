
#include <stdlib.h>
#include <stdio.h>



// emcc node.c -g -o node.js -sEXPORTED_FUNCTIONS=_process -sEXPORTED_RUNTIME_METHODS=ccall,cwrap -sMODULARIZE=1

// curl -X POST -H "Content-Type: application/json" -d '{"message": "%p %p %p %p %p %p", "length": 0}' http://localhost:3000/post-data

char* process(char* msg, int length) {

    char sensitive[] = "aaaaaaaa";

    char* result = (char*) malloc(length);
    
    // Copy msg into result
    sprintf(result, msg); // format string vulnerability

    // Do some sort of processing
    for(int i=0; i < length; i++) {
        result[i] += 1;
    }


    return result;

}