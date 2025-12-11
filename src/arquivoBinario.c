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

void inserir_produto(FILE* arquivo, Produto produto) {
    fwrite(&produto, sizeof(Produto), 1, arquivo);
}

void inserir_transacao_mestre(FILE* arquivo, TransacaoProduto transacao) {
    Produto produto;

    produto.codigo = transacao.codigo;
    strcpy(produto.nome, transacao.nome);
    produto.quantidade = transacao.quantidade;

    fwrite(&produto, sizeof(Produto), 1, arquivo);
}

void inserir_transacao(FILE* arquivo, TransacaoProduto transacao) {
    fwrite(&transacao, sizeof(TransacaoProduto), 1, arquivo);
}

int ler_produto(FILE* arquivo, Produto* produto) {
    return fread(produto, sizeof(Produto), 1, arquivo);
}

int ler_transacao(FILE* arquivo, TransacaoProduto* transacao) {
    return fread(transacao, sizeof(TransacaoProduto), 1, arquivo);
}

void imprimir_produto(Produto produto) {
    printf("%d | %s | %d\n", produto.codigo, produto.nome, produto.quantidade);
}

void imprimir_transacao(TransacaoProduto transacao) {
    printf("%d | %c | %s | %d\n", transacao.codigo, transacao.tipo, transacao.nome, transacao.quantidade);
}


void dados_teste() {
    FILE* mestre = fopen("mestre.bin", "wb");
    FILE* transacoes = fopen("transacoes.bin", "wb");

    if(mestre != NULL && transacoes != NULL) {
        Produto vet_produtos[6] = {{101, "prego", 20}, {102, "martelo", 2}, {120, "parafuso", 30},
                               {122, "porca", 44}, {130, "chave inglesa", 3}, {133, "alicate", 1}};

        TransacaoProduto vet_transacoes[8] ={{101, 'E', "", 0}, {102, 'A', "martelo", 4}, {110, 'I', "arruela", 5},
                                         {123, 'I', "chave de boca", 1}, {130, 'A', "chave inglesa", 5},
                                         {133, 'E', "", 0}, {134, 'I', "arrebite", 8}, {135, 'I', "arame", 3}};
        
        fwrite(&vet_produtos, sizeof(Produto), 6, mestre);
        fwrite(&vet_transacoes, sizeof(TransacaoProduto), 8, transacoes);

        fclose(mestre);
        fclose(transacoes);
    }
}
