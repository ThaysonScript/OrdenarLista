#ifndef INSERCTION_SORT_HEADER_H
#define INSERCTION_SORT_HEADER_H
#define NOME 100

/** @struct FuncionariosInserction
 *  @brief Uma estrutura para criar novos FuncionariosInserction
 * 
 *  @attention char FuncionariosInserction::nome[NOME]
 *  Uma variável de nome de funcionario
 * 
 *  @attention double FuncionariosInserction::salario
 *  Uma variável de salario de funcionario*/
struct FuncionariosInserction {
    char nome[NOME];
    double salario;
};

/** @brief Alocar estrutura de FuncionariosInserction
 *  @param struct FuncionariosInserction *funcionario
 *  @return endereco para nova estrutura alocada*/
struct FuncionariosInserction *inicializarFuncionarioInserction(struct FuncionariosInserction *funcionarioInserction);

/** @brief Desalocar estrutura de FuncionariosInserction
 *  @param struct FuncionariosInserction *funcionario
 *  @return nao retorna nada*/
void desalocarFuncionarioInserction(struct FuncionariosInserction *funcionarioInserction);

void ordenarPorInserction();
void inserctionSort();

/** Operacoes de C.R.U.D */
void criarInserction();
void lerInserction();
void atualizarInserction();
void deletarInserction();

#endif