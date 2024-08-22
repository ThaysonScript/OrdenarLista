#ifndef ORDENACAO_H
#define ORDENACAO_H
#define NOME 50

// struct de funcionarios
struct Funcionarios {
    char nome[NOME];
    double salario;
};

// operacoes de crud
void criar();
void ler();
void atualizar();
void deletar();

#endif