#ifndef ORDENACAO_H
#define ORDENACAO_H
#define NOME 100

/** @struct Funcionarios
 *  @brief Uma estrutura para criar novos funcionarios
 * 
 *  @attention char Funcionarios::nome[NOME]
 *  Uma variável de nome de funcionario
 * 
 *  @attention double Funcionarios::salario
 *  Uma variável de salario de funcionario*/
struct Funcionarios {
    char nome[NOME];
    double salario;
};

/** @brief Alocar estrutura de Funcionarios
 *  @param struct Funcionarios *funcionario
 *  @return endereco para nova estrutura alocada*/
struct Funcionarios *inicializarFuncionario(struct Funcionarios *funcionario);

/** @brief Desalocar estrutura de Funcionarios
 *  @param struct Funcionarios *funcionario
 *  @return nao retorna nada*/
void desalocarFuncionario(struct Funcionarios *funcionario);

/** Operacoes de C.R.U.D */
void criar();
void ler();
void atualizar();
void deletar();

#endif