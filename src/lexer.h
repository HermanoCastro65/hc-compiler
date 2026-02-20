#ifndef LEXER_H
#define LEXER_H

// Enumeração dos tipos de tokens
typedef enum {
    TOKEN_NUMBER,       // Número inteiro
    TOKEN_IDENTIFIER,   // Nome de variável ou função
    TOKEN_KEYWORD,      // Palavra reservada da linguagem
    TOKEN_ASSIGN,       // Operador =
    TOKEN_EOF           // Fim da entrada
} TokenType;

// Estrutura que representa um token
typedef struct {
    TokenType type;     // Tipo do token
    char lexeme[64];    // Texto original do token
    int line;           // Linha atual (para futuras mensagens de erro)
} Token;

// Inicializa o lexer com o código fonte
void init_lexer(const char* source);

// Retorna o próximo token encontrado
Token get_next_token();

#endif
