/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 2 - Balance Line
    
    Código principal do programa.
*/

#include <stdio.h>
#include <utils.h>
#include <arquivoBinario.h>
#include <balanceLine.h>

void menu(void) {
    printf(" BALANCE LINE\n"
           "--------------\n"
           "1. Carregar arquivo mestre\n"
           "2. Imprimir arquivo mestre"
           "3. Inserir transação\n"
           "4. Imprimir arquivo de transações\n"
           "5. Carregar teste");
}

int main(void) {
    printf("\n");

    dados_teste();

    FILE* mestre = fopen("mestre.bin", "r");
    FILE* transacoes = fopen("transacoes.bin", "a+b");
    
    if(mestre != NULL) {
        printf(" Mestre\n--------\n");

        for(int i = 0; i < 6; i++) {
            Produto produto;
            ler_produto(mestre, &produto);
            imprimir_produto(produto);
        }

        printf("\n Transcacoes\n-------------\n");

        for(int i = 0; i < 8; i++) {
            TransacaoProduto transacao;
            ler_transacao(transacoes, &transacao);
            imprimir_transacao(transacao);
        }
        
        pausar();

        balanceLine(mestre, transacoes);

        FILE* novo_mestre = fopen("novo_mestre.bin", "r");

        if(novo_mestre != NULL) {
            int leu;
            Produto produto;

            rewind(novo_mestre);

            printf("\n Novo Mestre\n-------------\n");

            do {
                leu = ler_produto(novo_mestre, &produto);
                imprimir_produto(produto);
            } while(leu);
        }

        printf("\n");
        fclose(mestre);
        fclose(transacoes);
        fclose(novo_mestre);
    }
    
    return 0;
}
