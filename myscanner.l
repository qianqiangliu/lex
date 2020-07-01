%{
#include "myscanner.h"
%}
%option nounput
%option noinput

%%
:                       return COLON;
"db_type"               return TYPE;
"db_name"               return NAME;
"db_port"               return PORT;

[a-zA-Z][_a-zA-Z0-9]*   return IDENTIFIER;
[1-9][0-9]*             return INTEGER;
[ \t\n]*                ;
.                       fprintf(stderr, "unexpected character\n");
%%

int yywrap(void)
{
    return 1;
}
