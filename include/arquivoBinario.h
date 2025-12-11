/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 2 - Balance Line

    Funções para criação e manipulação de arquivos binários que representam
    um estoque de mercadorias e movimentações de estoque (transações).
*/

#ifndef ARQUIVOBINARIO_H
#define ARQUIVOBINARIO_H

typedef struct Sproduto {
    int codigo;
    char nome[32];
    int quantidade;
} Produto;

typedef struct Stransacao_produto {
    int codigo;
    char tipo;
    char nome[32];
    int quantidade;
} TransacaoProduto;

void inserir_produto(FILE* arquivo, Produto produto);

void inserir_transacao_mestre(FILE* arquivo, TransacaoProduto transacao);

void inserir_transacao(FILE* arquivo, TransacaoProduto transacao);

int ler_produto(FILE* arquivo, Produto* produto);

int ler_transacao(FILE* arquivo, TransacaoProduto* transacao);

void imprimir_produto(Produto produto);

void imprimir_transacao(TransacaoProduto transacao);

void dados_teste();

#endif
