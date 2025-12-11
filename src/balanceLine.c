/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 2 - Balance Line

    Implementação das funções em balanceLine.h.
*/

#include <stdio.h>
#include <arquivoBinario.h>
#include <balanceLine.h>

void balanceLine(FILE* mestre, FILE* transacoes) {
    if(mestre == NULL || transacoes == NULL) {
        return;
    }

    Mercadoria mercadoria = {0};
    TransacaoMercadoria transacao = {0};
    FILE* novo_mestre = fopen("novo_mestre.bin", "wb");

    if(novo_mestre != NULL) {
        rewind(mestre);
        rewind(transacoes);

        int leu_mestre = ler_mercadoria(mestre, &mercadoria);
        int leu_transacoes = ler_transacao(transacoes, &transacao);

        while(leu_mestre || leu_transacoes) {
            if(leu_mestre && leu_transacoes) {
                if(mercadoria.codigo < transacao.codigo) {
                    inserir_mercadoria(novo_mestre, mercadoria);
                    leu_mestre = ler_mercadoria(mestre, &mercadoria);
                }

                else if(mercadoria.codigo > transacao.codigo) {
                    if(transacao.tipo == 'I') {
                        inserir_transacao_mestre(novo_mestre, transacao);
                    }

                    leu_transacoes = ler_transacao(transacoes, &transacao);
                }
                // mesmo codigo
                else {
                    if(transacao.tipo == 'A') {
                        inserir_transacao_mestre(novo_mestre, transacao);
                        leu_mestre = ler_mercadoria(mestre, &mercadoria);
                        leu_transacoes = ler_transacao(transacoes, &transacao);
                    }
                    
                    else if(transacao.tipo == 'E') {
                        leu_mestre = ler_mercadoria(mestre, &mercadoria);
                        leu_transacoes = ler_transacao(transacoes, &transacao);
                    }
                    else {
                        // Tipo inválido: ignora a transação e avança apenas nela
                        // A mercadoria do mestre será processada no próximo loop
                        leu_transacoes = ler_transacao(transacoes, &transacao);
                    }
                }

            } else if(leu_transacoes) {
                if(transacao.tipo == 'I') {
                    inserir_transacao_mestre(novo_mestre, transacao);
                }
                // Sempre avança nas transações, mesmo se não for inserção
                leu_transacoes = ler_transacao(transacoes, &transacao);
            } else {
                inserir_mercadoria(novo_mestre, mercadoria);
                leu_mestre = ler_mercadoria(mestre, &mercadoria);
            }
        }

        fclose(novo_mestre);
    }
}