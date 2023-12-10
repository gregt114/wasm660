#include <stdio.h>
#include <stdlib.h>

// emcc format.c -g -o format.js -sEXPORTED_FUNCTIONS=_vuln,_main -sEXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]'


/*

%04p

*/

const char data[] = "OVERWRITE_ME";

char* vuln(char* msg) {

    // Dummy local arrays
    char array1[] = "AAAAAAAA";
    char array2[] = "BBBBBBBB";

    char* resp = (char*) malloc(256);

    // Vulnerable to format string exploit
    sprintf(resp, msg);

    printf("Message : %p\n", msg);
    printf("Response: %p\n", resp);

    return resp;
}

int main() {
    printf("%p\n", data);
    return 0;
}
