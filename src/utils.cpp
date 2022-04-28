#include "include/utils.h"

void utils::ClearScreen(){
    #if defined(_WIN32) || defined(_WIN64)
        system("CLS");

    #elif __linux__
        system("clear");
    
    #endif
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

char utils::getchar() {
    #if defined(_WIN32) || defined(_WIN64)
        char input;
        
        input = getch();
        fflush(stdin);

        return input;

    #elif __linux__
        char buf = 0;
        struct termios old = {0};
        fflush(stdout);
        if(tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if(tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if(read(0, &buf, 1) < 0)
            perror("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if(tcsetattr(0, TCSADRAIN, &old) < 0)
            perror("tcsetattr ~ICANON");
        printf("%c\n", buf);

        fflush(stdin);
        return buf;
    
    #endif
}