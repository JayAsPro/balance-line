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

typedef struct Smercadoria {
    int codigo;
    char nome[32];
    int quantidade;
} Mercadoria;

typedef struct Stransacao_mercadoria {
    int codigo;
    char tipo;
    char nome[32];
    int quantidade;
} TransacaoMercadoria;

void inserir_mercadoria(FILE* arquivo, Mercadoria mercadoria);

void inserir_transacao_mestre(FILE* arquivo, TransacaoMercadoria transacao);

void inserir_transacao(FILE* arquivo, TransacaoMercadoria transacao);

int ler_mercadoria(FILE* arquivo, Mercadoria* mercadoria);

int ler_transacao(FILE* arquivo, TransacaoMercadoria* transacao);

void imprimir_mercadoria(Mercadoria mercadoria);

void imprimir_transacao(TransacaoMercadoria transacao);

void dados_teste();

#endif
