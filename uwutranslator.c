#include <stdio.h>
#include <stdlib.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");
    char c = fgetc(f);
    char check,check1;
    while (c != EOF) {
        switch(c) {
            case 'r' :
            case 'l' :
                c = 'w';
                break;
            case 'R' :
            case 'L' :
                c = 'R';
                break;
            case 't' :
                check = fgetc(f);
                if (check == 'H' || check == 'h') {
                    c = 'd';
                } else {
                    check1 = check;
                    check = c;
                    c = check1;
                    fputc(check, stdout);
                }
                break;
            case 'T' :
                check = fgetc(f);
                if (check == 'H' || check =='h') {
                    c = 'D';
                } else {
                    check1 = check;
                    check = c;
                    c = check1;
                    fputc(check, stdout);
                }
            default: 
                break;
        }
        fputc(c, stdout);
        c = fgetc(f);
    }
    printf("\n");
    return 0;
}
