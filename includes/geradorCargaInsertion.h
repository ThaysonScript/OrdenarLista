#ifndef GERADOR_CARGA_INSERTION_H
#define GERADOR_CARGA_INSERTION_H

// Função para gerar um nome aleatório
void gerarNome(struct FuncionariosInsertion* funcionario, int tamanhoMin, int tamanhoMax);

// Função para gerar um salário aleatório
int gerarSalario(struct FuncionariosInsertion* funcionario, int min, int max);

void geradorCarga(int carga, struct FuncionariosInsertion** novoFuncionario, int* qttFuncionario);

#endif