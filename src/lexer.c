#include <ctype.h>
#include <string.h>
#include "lexer.h"

// Armazena o código fonte
static const char* input;

// Posição atual
static int position;

// Linha atual
static int current_line;

/*
    Verifica se uma string é palavra reservada
*/
int is_keyword(const char* str) {
    return strcmp(str, "integer_type") == 0 ||
           strcmp(str, "return_value") == 0 ||
           strcmp(str, "while_loop") == 0 ||
           strcmp(str, "in_condition") == 0 ||
           strcmp(str, "otherwise_do") == 0;
}

/*
    Inicializa o lexer
*/
void init_lexer(const char* source) {
    input = source;
    position = 0;
    current_line = 1;
}

/*
    Retorna o próximo token
*/
Token get_next_token() {

    Token token;

    // Ignorar espaços
    while (input[position] == ' ') {
        position++;
    }

    // Reconhecer número
    if (isdigit(input[position])) {
        int i = 0;

        while (isdigit(input[position])) {
            token.lexeme[i++] = input[position++];
        }

        token.lexeme[i] = '\0';
        token.type = TOKEN_NUMBER;
        token.line = current_line;

        return token;
    }

    // Reconhecer identificador ou palavra reservada
    if (isalpha(input[position])) {
        int i = 0;

        while (isalnum(input[position]) || input[position] == '_') {
            token.lexeme[i++] = input[position++];
        }

        token.lexeme[i] = '\0';
        token.line = current_line;

        if (is_keyword(token.lexeme)) {
            token.type = TOKEN_KEYWORD;
        } else {
            token.type = TOKEN_IDENTIFIER;
        }

        return token;
    }

    // Reconhecer operador =
    if (input[position] == '=') {
        token.lexeme[0] = '=';
        token.lexeme[1] = '\0';
        token.type = TOKEN_ASSIGN;
        token.line = current_line;
        position++;

        return token;
    }

    // Fim da entrada
    token.type = TOKEN_EOF;
    strcpy(token.lexeme, "EOF");
    token.line = current_line;

    return token;
}
