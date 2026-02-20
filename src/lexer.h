#ifndef LEXER_H
#define LEXER_H

// Enumeração que define todos os tipos de tokens possíveis
typedef enum {
    TOKEN_NUMBER,       // Número inteiro
    TOKEN_IDENTIFIER,   // Nome de variável ou função
    TOKEN_ASSIGN,       // Operador =
    TOKEN_EOF           // Fim do arquivo
} TokenType;

// Estrutura que representa um token
typedef struct {
    TokenType type;     // Tipo do token
    char lexeme[64];    // Texto original do token
    int line;           // Linha onde o token foi encontrado
} Token;

// Inicializa o lexer com o código fonte
void init_lexer(const char* source);

// Retorna o próximo token encontrado
Token get_next_token();

#endif
