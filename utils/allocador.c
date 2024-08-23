#include <stdlib.h>
#include "../includes/principalHeader.h"

struct Funcionarios *inicializarFuncionario(struct Funcionarios *funcionario) {
    funcionario = (struct Funcionarios*)malloc(sizeof(struct Funcionarios));
    return funcionario;
}

void desalocarFuncionario(struct Funcionarios *funcionario) {
    free(funcionario);

    funcionario = NULL;
}