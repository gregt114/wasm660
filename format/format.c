#include <stdio.h>
#include <stdlib.h>

// emcc format.c -g -o format.js -sEXPORTED_FUNCTIONS=_vuln -sEXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' -sMODULARIZE=1


/*

curl -X POST -H "Content-Type: application/json" -d '{"msg": "testing"}' localhost:3000/api/

*/

char* vuln(char* msg) {

    // Dummy local arrays
    char array1[] = "AAAAAAAA";
    char array2[] = "BBBBBBBB";

    char* resp = (char*) malloc(256);

    // Vulnerable to format string exploit
    sprintf(resp, msg);

    return resp;
}
