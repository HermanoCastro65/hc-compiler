#include <stdio.h>
#include <string.h>
#include "../src/lexer.h"

/*
    Função auxiliar para imprimir resultado do teste
*/
void print_result(const char* test_name, int passed) {
    if (passed) {
        printf("%s: PASS\n", test_name);
    } else {
        printf("%s: FAILED\n", test_name);
    }
}

/*
    Teste: reconhecer número
*/
void test_number_token() {
    init_lexer("123");

    Token token = get_next_token();

    int passed = (token.type == TOKEN_NUMBER) &&
                 (strcmp(token.lexeme, "123") == 0);

    print_result("test_number_token", passed);
}

/*
    Teste: reconhecer identificador
*/
void test_identifier_token() {
    init_lexer("idade");

    Token token = get_next_token();

    int passed = (token.type == TOKEN_IDENTIFIER) &&
                 (strcmp(token.lexeme, "idade") == 0);

    print_result("test_identifier_token", passed);
}

/*
    Teste: reconhecer operador =
*/
void test_assign_token() {
    init_lexer("=");

    Token token = get_next_token();

    int passed = (token.type == TOKEN_ASSIGN);

    print_result("test_assign_token", passed);
}

/*
    Função principal que executa todos os testes
*/
int main() {

    printf("Running Lexer Tests\n");
    printf("--------------------\n");

    test_number_token();
    test_identifier_token();
    test_assign_token();

    printf("--------------------\n");
    printf("End of tests\n");

    return 0;
}
