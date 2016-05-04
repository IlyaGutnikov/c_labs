#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {

    srand(time(0));
    int n = 0;
    int i = 0;
    char s[100];

    n = 1 + rand() %10;

    printf("Введите ваше имя:\n");

    scanf("%99s", s);

    for (i = 0; i< n; i++)
    {
        if (n%2 == 0) {

            printf("Привет, %s \n", s);

        }

        else {

            printf("Здорово, %s \n", s);

        }
    }


    return 0;
}
