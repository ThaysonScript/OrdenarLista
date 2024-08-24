#ifndef INSERCTION_SORT_HEADER_H
#define INSERCTION_SORT_HEADER_H
#define NOME 100

/** @struct FuncionariosInsertion
 *  @brief Uma estrutura para criar novos FuncionariosInsertion
 * 
 *  @var char FuncionariosInsertion::nome[NOME]
 *  Uma variável de nome de funcionario
 * 
 *  @var double FuncionariosInsertion::salario
 *  Uma variável de salario de funcionario*/
struct FuncionariosInsertion {
    char nome[NOME];
    double salario;
};

/** @brief Alocar estrutura de FuncionariosInsertion
 *  @param struct FuncionariosInsertion *funcionario
 *  @return endereco para nova estrutura alocada*/
struct FuncionariosInsertion *inicializarFuncionarioInsertion(struct FuncionariosInsertion *funcionarioInserction);

/** @brief Desalocar estrutura de FuncionariosInsertion
 *  @param struct FuncionariosInsertion *funcionario
 *  @return nao retorna nada*/
void desalocarFuncionarioInsertion(struct FuncionariosInsertion *funcionarioInserction);

/** Operacoes de C.R.U.D */
void criarInsertion();
void lerInsertion();
void atualizarInsertion();
void deletarInsertion();


void ordenarPorInsertion();
void insertionSort();

#endif
