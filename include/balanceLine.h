/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 2 - Balance Line

    Funções para atualizar um arquivo binário a partir de um arquivo de
    transações utilizando a técnica do balance line.
*/

#ifndef BALANCELINE_H
#define BALANCELINE_H

#include <stdio.h>

void balanceLine(FILE* mestre, FILE* transacoes);

#endif
