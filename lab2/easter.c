#include <stdio.h>

int main(void) {
    int Y; /* Year */
    int date;
    /* Y = 1994; */

    /* date = calculate_Easter_date(Y);
    printf("%i\n", date); */

    while(1) {

        if((scanf("%d", &Y)) == EOF) {
            break;
        }

        fprintf(stderr, "%d", Y);

        date = calculate_Easter_date(Y);

        if(date == 0) {
            fprintf(stderr, "Year is "
            "out of range "
            "from 1582 to 39999\n");
        }

        if(date > 0) {
            printf("%d - Апрель %d\n", Y, date);
        }
        if(date < 0) {
            printf("%d - Март %d\n", Y, -date);
        }
    }    


    return 0;
}

int calculate_Easter_date(int Y) {

    int G; /* Golden Year */
    int C; /* Century */
    int X; /* X is the skipped leap years */
    int Z; /* Z is a correction factor for the moon's orbit */
    int D;
    int E;
    int N;


    G = (Y % 19) + 1; /* Step 1 */
    C = (Y / 100) + 1; /* Step 2 */

    X = (3 * C / 4) - 12; /* Step 3 */
    Z = ((8 * C + 5) / 25) - 5;

    D = (5 * Y / 4) - X - 10; /* Step 4 */

    /* Step 5 */
    E = (11 * G + 20 + Z - X) % 30;

    if (((E == 25) && (G > 11)) || (E == 24)) {

        E = E + 1;
    }

    /* Step 6 */
    N = 44 - E;
    if (N < 21) {

        N += 30;
    }

    /* Step 7 */
    N = N + 7 - ((D + N) % 7);

    /* Step 8 */
    if (N > 31) {

        /* printf("APRIL \n"); */
        N = N - 31;
        return N;
    }

    else {

        /* printf("MARCH\n"); */
        return -N;
    }

}
