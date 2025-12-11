/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 2 - Balance Line

    Implementação das funções em arquivoBinario.h.
*/

#include <stdio.h>
#include <string.h>
#include <utils.h>
#include <arquivoBinario.h>

void inserir_mercadoria(FILE* arquivo, Mercadoria mercadoria) {
    if(arquivo != NULL) {
        fwrite(&mercadoria, sizeof(Mercadoria), 1, arquivo);
    }
}

void inserir_transacao_mestre(FILE* arquivo, TransacaoMercadoria transacao) {
    if(arquivo != NULL) {
        Mercadoria mercadoria;

        mercadoria.codigo = transacao.codigo;
        strcpy(mercadoria.nome, transacao.nome);
        mercadoria.quantidade = transacao.quantidade;

        fwrite(&mercadoria, sizeof(Mercadoria), 1, arquivo);
    }
}

void inserir_transacao(FILE* arquivo, TransacaoMercadoria transacao) {
    if(arquivo != NULL) {
        fwrite(&transacao, sizeof(TransacaoMercadoria), 1, arquivo);
    }
}

int ler_mercadoria(FILE* arquivo, Mercadoria* mercadoria) {
    if(arquivo == NULL || mercadoria == NULL) {
        return 0;
    }
    return fread(mercadoria, sizeof(Mercadoria), 1, arquivo);
}

int ler_transacao(FILE* arquivo, TransacaoMercadoria* transacao) {
    if(arquivo == NULL || transacao == NULL) {
        return 0;
    }
    return fread(transacao, sizeof(TransacaoMercadoria), 1, arquivo);
}

void imprimir_mercadoria(Mercadoria mercadoria) {
    printf("%d | %s | %d\n", mercadoria.codigo, mercadoria.nome, mercadoria.quantidade);
}

void imprimir_transacao(TransacaoMercadoria transacao) {
    printf("%d | %c | %s | %d\n", transacao.codigo, transacao.tipo, transacao.nome, transacao.quantidade);
}


void dados_teste() {
    FILE* mestre = fopen("mestre.bin", "wb");
    FILE* transacoes = fopen("transacoes.bin", "wb");

    if(mestre != NULL && transacoes != NULL) {
        Mercadoria vet_mercadorias[6] = {{101, "prego", 20}, {102, "martelo", 2}, {120, "parafuso", 30},
                               {122, "porca", 44}, {130, "chave inglesa", 3}, {133, "alicate", 1}};

        TransacaoMercadoria vet_transacoes[8] ={{101, 'E', "", 0}, {102, 'A', "martelo", 4}, {110, 'I', "arruela", 5},
                                         {123, 'I', "chave de boca", 1}, {130, 'A', "chave inglesa", 5},
                                         {133, 'E', "", 0}, {134, 'I', "arrebite", 8}, {135, 'I', "arame", 3}};
        
        fwrite(&vet_mercadorias, sizeof(Mercadoria), 6, mestre);
        fwrite(&vet_transacoes, sizeof(TransacaoMercadoria), 8, transacoes);

        fclose(mestre);
        fclose(transacoes);
    }
}
