#ifndef GERADOR_CARGA_SELECTION_H
#define GERADOR_CARGA_SELECTION_H

// Função para gerar um nome aleatório
void gerarNome(struct FuncionariosSelection* funcionario, int tamanhoMin, int tamanhoMax);

// Função para gerar um salário aleatório
int gerarSalario(struct FuncionariosSelection* funcionario, int min, int max);

void geradorCarga(int carga, struct FuncionariosSelection** novoFuncionario, int* qttFuncionario);

#endif