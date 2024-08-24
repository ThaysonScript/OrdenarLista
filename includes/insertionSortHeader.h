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
void alocarFuncionarioInsertion(struct FuncionariosInsertion** novoFuncionario, int* qtdFuncionario);

/** @brief Verificar alocacao */
void verificarAlocacao(struct FuncionariosInsertion** funcionarioInsertion);

/** @brief Desalocar estrutura de FuncionariosInsertion
 *  @param struct FuncionariosInsertion *funcionario
 *  @return nao retorna nada*/
void desalocarFuncionarioInsertion(struct FuncionariosInsertion** funcionarioInserction);

/** Operacoes de C.R.U.D */
int criarFuncionarioInsertion(struct FuncionariosInsertion** novoFuncionario, int* qttFuncionario);
void lerFuncionarioInsertion(struct FuncionariosInsertion** funcionarios, int* qttFuncionario);
void atualizarFuncionarioInsertion(struct FuncionariosInsertion** funcionarios, int* qttFuncionario);
void deletarFuncionarioInsertion(struct FuncionariosInsertion** funcionarios, int* qttFuncionario);

// algoritmo para ordenar
void ordenarPorInsertion();

// limpar termianl
void limparTela();

// chamada principal
void insertionSort();

#endif

#ifdef _WIN32
    #define COMANDO_LIMPAR "cls"
#else
    #define COMANDO_LIMPAR "reset"
#endif