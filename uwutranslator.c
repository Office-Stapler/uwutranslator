#include <stdio.h>
#include <stdlib.h>

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

#define COLOUR YEL

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Can't open %s\n",argv[1]);
        exit(1);
    }
    char c = fgetc(f);
    while (c != EOF) {
        if (c == 'r' || c == 'R' || c == 'l' || c == 'L') {
            printf(COLOUR);
            c = (c == 'r' || c == 'l') ? 'w' : 'W';
        } else if (c == 't' || c == 'T') {
            char temp = c;
            c = fgetc(f);
            if (c == 'h' || c == 'H') {
                printf(COLOUR);
                c = (temp == 'T') ? 'D' : 'd';
            } else {
                putchar(temp);
            }
        }
        putchar(c);
        printf(WHT);
        c = fgetc(f);
    }
    fclose(f);
    return 0;
}
