#include <ctype.h>   // Para isdigit e isalpha
#include <string.h>  // Para strcpy
#include "lexer.h"

// Ponteiro para armazenar o código fonte
static const char* input;

// Posição atual no código
static int position;

// Linha atual (para debug futuro)
static int current_line;

// Inicializa o lexer
void init_lexer(const char* source) {
    input = source;
    position = 0;
    current_line = 1;
}

// Função principal que retorna o próximo token
Token get_next_token() {

    Token token;

    // Ignorar espaços
    while (input[position] == ' ') {
        position++;
    }

    // Verificar número
    if (isdigit(input[position])) {
        int i = 0;

        // Captura todos os dígitos consecutivos
        while (isdigit(input[position])) {
            token.lexeme[i++] = input[position++];
        }

        token.lexeme[i] = '\0';
        token.type = TOKEN_NUMBER;
        token.line = current_line;

        return token;
    }

    // Verificar identificador (letras)
    if (isalpha(input[position])) {
        int i = 0;

        while (isalnum(input[position])) {
            token.lexeme[i++] = input[position++];
        }

        token.lexeme[i] = '\0';
        token.type = TOKEN_IDENTIFIER;
        token.line = current_line;

        return token;
    }

    // Verificar operador =
    if (input[position] == '=') {
        token.lexeme[0] = '=';
        token.lexeme[1] = '\0';
        token.type = TOKEN_ASSIGN;
        token.line = current_line;
        position++;

        return token;
    }

    // Fim do código
    token.type = TOKEN_EOF;
    strcpy(token.lexeme, "EOF");
    token.line = current_line;

    return token;
}
