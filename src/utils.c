/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 2 - Balance Line

    Implementação das funções em utils.h.
*/

#include <stdio.h>

void limpar_buffer(void) {
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

void pausar(void) {
    printf("\nENTER para continuar...");
    limpar_buffer();
}

void limpar_tela(void) {
    printf("\033c\033[H");
}
