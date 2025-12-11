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
    limpar_tela();
    printf(" BALANCE LINE\n"
           "--------------\n"
           "1. Imprimir arquivo mestre\n"
           "2. Imprimir arquivo de transações\n"
           "3. Carregar teste\n"
           "4. Executar Balance Line\n"
           "5. Imprimir novo mestre\n"
           "0. Sair\n"
           "\nEscolha uma opção: ");
}

void imprimir_mestre(void) {
    FILE* mestre = fopen("mestre.bin", "rb");
    
    if(mestre == NULL) {
        printf("\nErro: não foi possível abrir o arquivo mestre.bin\n");
        pausar();
        return;
    }

    printf("\n Mestre\n--------\n");
    Mercadoria mercadoria;
    int leu_mercadoria;
    do {
        leu_mercadoria = ler_mercadoria(mestre, &mercadoria);
        if(leu_mercadoria) {
            imprimir_mercadoria(mercadoria);
        }
    } while(leu_mercadoria);

    fclose(mestre);
    pausar();
}

void imprimir_transacoes(void) {
    FILE* transacoes = fopen("transacoes.bin", "rb");
    
    if(transacoes == NULL) {
        printf("\nErro: não foi possível abrir o arquivo transacoes.bin\n");
        pausar();
        return;
    }

    printf("\n Transacoes\n-------------\n");
    TransacaoMercadoria transacao;
    int leu_transacao;
    do {
        leu_transacao = ler_transacao(transacoes, &transacao);
        if(leu_transacao) {
            imprimir_transacao(transacao);
        }
    } while(leu_transacao);

    fclose(transacoes);
    pausar();
}

void executar_balance_line(void) {
    FILE* mestre = fopen("mestre.bin", "rb");
    FILE* transacoes = fopen("transacoes.bin", "rb");
    
    if(mestre == NULL || transacoes == NULL) {
        if(mestre == NULL) {
            printf("\nErro: não foi possível abrir o arquivo mestre.bin\n");
        }
        if(transacoes == NULL) {
            printf("Erro: não foi possível abrir o arquivo transacoes.bin\n");
        }
        if(mestre != NULL) fclose(mestre);
        if(transacoes != NULL) fclose(transacoes);
        pausar();
        return;
    }

    printf("\nExecutando Balance Line...\n");
    balanceLine(mestre, transacoes);
    printf("Balance Line executado com sucesso!\n");
    
    fclose(mestre);
    fclose(transacoes);
    pausar();
}

void imprimir_novo_mestre(void) {
    FILE* novo_mestre = fopen("novo_mestre.bin", "rb");
    
    if(novo_mestre == NULL) {
        printf("\nErro: não foi possível abrir o arquivo novo_mestre.bin\n");
        printf("Execute o Balance Line primeiro (opção 4)\n");
        pausar();
        return;
    }

    printf("\n Novo Mestre\n-------------\n");
    Mercadoria mercadoria;
    int leu_mercadoria;
    do {
        leu_mercadoria = ler_mercadoria(novo_mestre, &mercadoria);
        if(leu_mercadoria) {
            imprimir_mercadoria(mercadoria);
        }
    } while(leu_mercadoria);

    fclose(novo_mestre);
    pausar();
}

int main(void) {
    int opcao;
    
    do {
        menu();
        if(scanf("%d", &opcao) != 1) {
            opcao = -1; // Valor inválido para cair no default
        }
        limpar_buffer();
        
        switch(opcao) {
            case 1:
                imprimir_mestre();
                break;
            case 2:
                imprimir_transacoes();
                break;
            case 3:
                dados_teste();
                printf("\nArquivos de teste carregados com sucesso!\n");
                pausar();
                break;
            case 4:
                executar_balance_line();
                break;
            case 5:
                imprimir_novo_mestre();
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
                break;
        }
    } while(opcao != 0);
    
    return 0;
}
