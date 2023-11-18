

// clang clang.c -o clang.wasm --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all

// Imported JS functions from env object
void __attribute__((import_module("env"), import_name("print"))) print(int);
void __attribute__((import_module("env"), import_name("print_string"))) print_string(const char*, int);

const char test[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

int main(){

    int x = 1;
    const char test[] = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    print_string(test, 10);
    print(test[0]);
    x = 0;
    *(int*)x = 4;

    return x+1;
}