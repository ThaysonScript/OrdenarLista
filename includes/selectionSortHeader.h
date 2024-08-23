#ifndef SELECTION_SORT_HEADER_H
#define SELECTION_SORT_HEADER_H
#define NOME 100

/** @struct FuncionariosSelection
 *  @brief Uma estrutura para criar novos FuncionariosSelection
 * 
 *  @attention char FuncionariosSelection::nome[NOME]
 *  Uma variável de nome de funcionario
 * 
 *  @attention double FuncionariosSelection::salario
 *  Uma variável de salario de funcionario*/
struct FuncionariosSelection {
    char nome[NOME];
    double salario;
};

/** @brief Alocar estrutura de FuncionariosSelection
 *  @param struct FuncionariosSelection *funcionario
 *  @return endereco para nova estrutura alocada*/
struct FuncionariosSelection *inicializarFuncionarioSelection(struct FuncionariosSelection *funcionarioSelection);

/** @brief Desalocar estrutura de FuncionariosSelection
 *  @param struct FuncionariosSelection *funcionario
 *  @return nao retorna nada*/
void desalocarFuncionarioSelection(struct FuncionariosSelection *funcionarioSelection);

void ordenarPorSelection();
void selectionSort();

/** Operacoes de C.R.U.D */
void criarSelection();
void lerSelection();
void atualizarSelection();
void deletarSelection();

#endif