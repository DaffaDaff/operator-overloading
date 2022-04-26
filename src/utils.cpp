#include "include/utils.h"

void utils::ClearScreen(){
    system("clear");
    system("CLS");
}

int utils::GetDigit(int value){
    if(value == 0) return 1;

    int i = 0;

    while(value != 0){
        value = value / 10;
        i++;
    }

    return i;
}

int utils::GetDigit(int value, int digit){
    int n = 0;

    for(int i = 0; i < digit; i++){
        n = value % 10;
        value = value / 10;
    }

    return n;
}

char utils::getch() {
    system("stty raw"); 

    char input;
    
    input = getchar();
    fflush(stdin);

    system("stty cooked"); 

    return input;
}