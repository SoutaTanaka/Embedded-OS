#include "defines.h"
#include "serial.h"
#include "lib.h"

int main(void){
    static char buf[16];

    puts("Hello World!\n");

    while(1) {
        puts("kozos> ");
        gets(buf);

        if(!strncmp(buf, "echo", 4)){
            puts(buf + 4);
            puts("\n");
        }else if(!strcmp(buf, "exit")){
            break;
        }else{
            puts("unknowon.\n");
        }
    }
    return 0;
}



