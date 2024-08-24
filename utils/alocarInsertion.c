#include <stdlib.h>
#include "../includes/insertionSortHeader.h"

struct FuncionariosInsertion *inicializarFuncionarioInsertion(struct FuncionariosInsertion *funcionarioInsertion) {
    funcionarioInsertion = (struct FuncionariosInsertion*)malloc(sizeof(struct FuncionariosInsertion));
    return funcionarioInsertion;
}

void desalocarFuncionarioInsertion(struct FuncionariosInsertion *funcionarioInsertion) {
    free(funcionarioInsertion);

    funcionarioInsertion = NULL;
}