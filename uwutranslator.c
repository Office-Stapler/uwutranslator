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
    char check,check1;
    while (c != EOF) {
        switch(c) {
            case 'r' :
            case 'l' :
				printf(COLOUR);
                c = 'w';
                break;
            case 'R' :
            case 'L' :
				printf(COLOUR);
                c = 'W';
                break;
            case 't' :
                check = fgetc(f);
                if (check == 'H' || check == 'h') {
					printf(COLOUR);
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
					printf(COLOUR);
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
		printf(WHT);
        c = fgetc(f);
    }
    printf("\n");
    return 0;
}
