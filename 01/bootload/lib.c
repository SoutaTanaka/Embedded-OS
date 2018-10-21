#include "defines.h"
#include "serial.h"
#include "lib.h"


int putc(unsigned char c){
    if(c == '\n')
        serial_send_byte(SERIAL_DEFAULT_DEVICE, '\r');
    return serial_send_byte(SERIAL_DEFAULT_DEVICE, c);
}

int puts(unsigned char *str){
    while (*str)
        putc(*(str++));
    return 0;
}


int putxval(unsigned long value, int column){
    char buf[9];
    char *p;

    p = buf + sizeof(buf) - 1;
    *(p--) = '\0';

    if(!value && column){
        column++;
    }

    while(value || column){
         *(p--) = "0123456789abcdef"[value & 0xf];
        value >>= 4;
        //*(p--) = "0123456789"[value & 10];
        //value /= 10;

        if(column) column--;
    }

    puts(p + 1);

    return 0;
}
