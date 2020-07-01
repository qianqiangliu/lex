/*
 * ./myscanner < config.in
 */
#include <stdio.h>

#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char *yytext;

char *names[] = {NULL, "type", "name", "port"};

int main(int argc, char **argv)
{
    int ntoken, vtoken;

    ntoken = yylex();

    while (ntoken) {
        if (yylex() != COLON) {
            fprintf(stderr, "Syntax error in line %d, Expected ':' but found %s\n", yylineno, yytext);
            return 1;
        }
        vtoken = yylex();
        switch (ntoken) {
        case TYPE:
        case NAME:
            if (vtoken != IDENTIFIER) {
                fprintf(stderr, "Syntax error in line %d, Expected identifier but found %s\n", yylineno, yytext);
                return 1;
            }
            printf("%s is set %s\n", names[ntoken], yytext);
            break;
        case PORT:
            if (vtoken != INTEGER) {
                fprintf(stderr, "Syntax error in line %d, Expected integer but found %s\n", yylineno, yytext);
                return 1;
            }
            printf("%s is set %s\n", names[ntoken], yytext);
            break;
        }
        ntoken = yylex();
    }

    return 0;
}
