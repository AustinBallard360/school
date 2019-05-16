/* This C program demonstartes switch statements w/ using breaks */
/* This C program was dilligently copied by LUKE SCHULZ 1/17/19 */
#include <stdio.h>
main() {
        char ch = '+';
        int a = 10, b = 20;
        double f;
        printf("ch = %c\n", ch);
        switch(ch) {

        case '+': f = a + b; printf("f = %.0f\n", f);break;
        case '-': f = a - b; printf("f = %.0f\n", f);break;
        case '*': f = a * b; printf("f = %.0f\n", f);break;
        case '/': f = a / b; printf("f = %.0f\n", f);break;

        default: printf("invalid operator\n");
        }
         ch = '-';
        printf("ch = %c\n", ch);
        switch(ch) {

        case '+': f = a + b; printf("f = %.0f\n", f);break;
        case '-': f = a - b; printf("f = %.0f\n", f);break;
        case '*': f = a * b; printf("f = %.0f\n", f);break;
        case '/': f = a / b; printf("f = %.0f\n", f);break;
        default: printf("invalid operator\n");
        }

        ch = '/';
        printf("ch = %c\n", ch);
        switch(ch) {

        case '+': f = a + b; printf("f = %.0f\n", f);break;
        case '-': f = a - b; printf("f = %.0f\n", f);break;
        case '*': f = a * b; printf("f = %.0f\n", f);break;
        case '/': f = a / b; printf("f = %.0f\n", f);break;
        default: printf("invalid operator\n");
        }
        ch = '%';
        printf("ch = %c\n", ch);
        switch(ch) {

        case '+': f = a + b; printf("f = %.0f\n", f);break;
        case '-': f = a - b; printf("f = %.0f\n", f);break;
        case '*': f = a * b; printf("f = %.0f\n", f);break;
        case '/': f = a / b; printf("f = %.0f\n", f);break;
        default: printf("invalid operator\n");
        }
}
// this is a comment. we are done here boys