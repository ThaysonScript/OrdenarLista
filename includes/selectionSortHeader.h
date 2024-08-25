#ifndef SELECTION_SORT_HEADER_H
#define SELECTION_SORT_HEADER_H
#define NOME 100

/** @struct FuncionariosSelection
 *  @brief Uma estrutura para criar novos FuncionariosSelection
 * 
 *  @var char FuncionariosSelection::nome[NOME]
 *  Uma variável de nome de funcionario
 * 
 *  @var double FuncionariosSelection::salario
 *  Uma variável de salario de funcionario*/
struct FuncionariosSelection {
    char nome[NOME];
    double salario;
};

/** @brief Alocar estrutura de FuncionariosSelection
 *  @param struct FuncionariosSelection *funcionario
 *  @return endereco para nova estrutura alocada*/
void alocarFuncionarioSelection(struct FuncionariosSelection** novoFuncionario, int* qtdFuncionario);

/** @brief Verificar alocacao */
void verificarAlocacaoSelection(struct FuncionariosSelection** funcionarioSelection);

/** @brief Desalocar estrutura de FuncionariosSelection
 *  @param struct FuncionariosSelection *funcionario
 *  @return nao retorna nada*/
void desalocarFuncionarioSelection(struct FuncionariosSelection** funcionarioSelection);

/** Operacoes de C.R.U.D */
int criarFuncionarioSelection(struct FuncionariosSelection** novoFuncionario, int* qttFuncionario);
void lerFuncionarioSelection(struct FuncionariosSelection** funcionarios, int* qttFuncionario);
void atualizarFuncionarioSelection(struct FuncionariosSelection** funcionarios, int* qttFuncionario);
void deletarFuncionarioSelection(struct FuncionariosSelection** funcionarios, int* qttFuncionario);

// algoritmo para ordenar
void ordenarPorSelection(struct FuncionariosSelection** funcionarios, int* qttFuncionario);

// limpar termianl
void limparTelaSelection();

// chamada principal
void selectionSort();

#endif

#ifdef _WIN32
    #define COMANDO_LIMPAR "cls"
#else
    #define COMANDO_LIMPAR "reset"
#endif