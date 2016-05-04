#include <stdio.h>

int main(void) {

    char s[100];

    printf("Введите ваше имя:\n");

    scanf("%99s", s);

    printf("Ваше имя:%s\n", s);


    return 0;
}