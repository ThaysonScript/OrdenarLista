#include <stdio.h>
#include <string.h>
#include "../includes/menus.h"
#include "../includes/insertionSortHeader.h"

void criarInsertion() {
    puts("criar");
}

void lerInsertion() {
    puts("ler");
}

void atualizarInsertion() {
    puts("atualizar");
}

void deletarInsertion() {
    puts("deletar");
}

void ordenarPorInsertion() {
    puts("ordenarPorInsercao");
}

void insertionSort() {
    struct FuncionariosInsertion *novoFuncionario = NULL;

    int gerandoDados = desejaGerarDados();

    if (gerandoDados >= 1 && gerandoDados <= 5)
        printf("\ngerando....\n");

    else if (gerandoDados == 6 || gerandoDados == 0)
        printf("nao gerando dados");

    
}