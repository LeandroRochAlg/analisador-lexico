%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reconhecida() {
    printf("Cadeia reconhecida\n");
}

void nao_reconhecida() {
    printf("Cadeia não reconhecida\n");
}
%}

%%

# Regras para a linguagem A
"i(" ("3"|"4"|"5") ("+"|"-") ("6"|"7"|"8") ">" "1" ")" {
    reconhecida();
}

"i(" ("6"|"7"|"8") "-" ("3"|"4"|"5") ")" ("3"|"4"|"5") ("+"|"-") ("6"|"7"|"8") "e" ("3"|"4"|"5") ("+"|"-") ("6"|"7"|"8") {
    reconhecida();
}

"w(x=[3-8]>)3)" ("3"|"4"|"5") ("+"|"-") ("6"|"7"|"8") "x=-3" {
    reconhecida();
}

# Regras para a linguagem B
"0"* "1" ("0"|"1")+ {
    reconhecida();
}

# Regras para a linguagem C
([aeiouAEIOU][bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ][aeiouAEIOU]) {
    reconhecida();
}

. {
    nao_reconhecida();
}

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Uso: ./AnaLex [input_string]\n");
        return 1;
    }

    yy_scan_string(argv[1]);
    yylex();

    return 0;
}