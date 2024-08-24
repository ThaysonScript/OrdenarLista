#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/menus.h"
#include "../includes/insertionSortHeader.h"

void limparTela() {
    system(COMANDO_LIMPAR);
}

void verificarAlocacao(struct FuncionariosInsertion** funcionarioInsertion) {
    if (*funcionarioInsertion == NULL) {
        puts("OCORREU PROBLEMA DE ALOCACAO DE FUNCIONARIOS");
        exit(EXIT_FAILURE);
    } else {
        puts("ALOCACAO DE FUNCIONARIOS BEM SUCEDIDA");
    }
}

/** ----------------------------------------------- ALOCAR ESTRUTURA
 * Alocar de forma dinamica a quantidade de estruturas que tiver vontade 
 */
void alocarFuncionarioInsertion(struct FuncionariosInsertion** novoFuncionario, int* qtdFuncionario) {
    if (*novoFuncionario == NULL) {
        puts("INICIALIZANDO CADASTRO DE FUNCIONARIOS");
        *novoFuncionario = (struct FuncionariosInsertion*)malloc(*qtdFuncionario * sizeof(struct FuncionariosInsertion));
    } else {
        puts("ADICIONANDO MAIS ARMAZENAMENTO DE FUNCIONARIOS");
        *novoFuncionario = (struct FuncionariosInsertion*)realloc(*novoFuncionario, (*qtdFuncionario) * sizeof(struct FuncionariosInsertion));
    }

    verificarAlocacao(novoFuncionario);
}

// ----------------------------------------------- DESALOCAR ESTRUTURA
void desalocarFuncionarioInsertion(struct FuncionariosInsertion** funcionarios) {
    if (*funcionarios != NULL) {
        free(*funcionarios);
        *funcionarios = NULL;
    }
}

// ----------------------------------------------- OPERACOES DE C.R.U.D
int criarFuncionarioInsertion(struct FuncionariosInsertion** novoFuncionario, int* qttFuncionario) {
    limparTela();
    int tempQtt;
    char novoNome[NOME];
    double novoSalario;

    printf("Deseja gerar quantos funcionarios: ");
    scanf("%i", &tempQtt);
    getchar();  // limpando buffer de entrada

    *qttFuncionario += tempQtt;

    alocarFuncionarioInsertion(novoFuncionario, qttFuncionario);

    for (int i = (*qttFuncionario - tempQtt); i < *qttFuncionario; i++) {
        printf("Digitar novo nome para funcionario %i: ", i + 1);
        fgets(novoNome, NOME, stdin);
        novoNome[strcspn(novoNome, "\n")] = '\0';

        strcpy((*novoFuncionario)[i].nome, novoNome);

        printf("Digitar novo salario para funcionario %i: ", i + 1);
        scanf("%lf", &novoSalario);
        getchar();

        (*novoFuncionario)[i].salario = novoSalario;
    }

    for (int j = 0; j < *qttFuncionario; j++) {
        puts("----------------- CADASTRADO -------------------");
        printf("funcionario - %i\n", (j + 1));
        puts("INFORMACOES CADASTRADAS:");
        printf("nome = %s\nsalario = %.3lf\n", (*novoFuncionario)[j].nome, (*novoFuncionario)[j].salario);
        puts("------------------------------------------------");
    }
}

void lerFuncionarioInsertion(struct FuncionariosInsertion** funcionarios, int* qttFuncionario) {
    limparTela();
    printf("Qtd de funcionários: %d\n", *qttFuncionario);

    for (int i = 0; i < *qttFuncionario; i++) {
        puts("----------------- CADASTRADO -------------------");
        printf("funcionario - %i\n", (i + 1));
        puts("INFORMACOES CADASTRADAS:");
        printf("nome = %s\nsalario = %.3lf\n", (*funcionarios)[i].nome, (*funcionarios)[i].salario);
        puts("------------------------------------------------");
    }
}

void atualizarFuncionarioInsertion(struct FuncionariosInsertion** funcionarios, int* qttFuncionario) {
    char nomeFuncionario[NOME], novoNome[NOME];
    double novoSalario;
    int escolha;

    puts("---------------------- LISTANDO FUNCIONARIOS ---------------------");
    lerFuncionarioInsertion(funcionarios, qttFuncionario);
    puts("------------------------------------------------------------------");

    puts("---------------------- ATUALIZANDO DADOS ---------------------");
    printf("DIGITE O NOME DO FUNCIONARIO: ");
    fgets(nomeFuncionario, NOME, stdin);
    nomeFuncionario[strcspn(nomeFuncionario, "\n")] = '\0';
    getchar();

    puts("DESEJA ATUALIZAR O QUE MEU CONSAGRADO?");
    puts("[1] - NOME");
    puts("[2] - SALARIO");
    puts("--------------------------------------------------------------");
    printf("ESCOLHA: ");
    scanf("%i", &escolha);

    if (escolha == 1) {
        for (int i = *qttFuncionario; i < *qttFuncionario; i++) {
            if ((*funcionarios)[i].nome == nomeFuncionario) {
                printf("FUNCIONARIO COM { %s } ENCONTRADO", (*funcionarios)[i].nome);

                printf("DIGITE O NOVO NOME PARA O ANTIGO FUNCIONARIO { %s }: ", (*funcionarios)[i].nome);
                fgets(novoNome, NOME, stdin);
                novoNome[strcspn(novoNome, "\n")] = '\0';

                strcpy((*funcionarios)[i].nome, novoNome);
            }
        }
    } else if (escolha == 2) {
        for (int i = *qttFuncionario; i < *qttFuncionario; i++) {
            if ((*funcionarios)[i].nome == nomeFuncionario) {
                printf("DIGITE O NOVO SALARIO DO FUNCIONARIO { %s } ENCONTRADO", (*funcionarios)[i].nome);
                scanf("%lf", &novoSalario);
                getchar();

                (*funcionarios)[i].salario = novoSalario;
            }
        }
    }

    puts("---------------------- LISTANDO FUNCIONARIOS ATUALIZADOS ---------------------");
    lerFuncionarioInsertion(funcionarios, qttFuncionario);
    puts("------------------------------------------------------------------------------");
}

void deletarFuncionarioInsertion(struct FuncionariosInsertion** funcionarios, int* qttFuncionario) {
    puts("deletar");
}

void ordenarPorInsertion() {
    puts("ordenarPorInsercao");
}

// ----------------------------------------------- CHAMADA PRINCIPAL
void insertionSort() {
    limparTela();

    int qttFuncionarios = 0;
    struct FuncionariosInsertion* funcionarios = NULL;

    while (1) {
        int escolha = menuPrincipalInsertion();

        if (escolha == 1) {
            criarFuncionarioInsertion(&funcionarios, &qttFuncionarios);
            
        } else if (escolha == 2) {
            lerFuncionarioInsertion(&funcionarios, &qttFuncionarios);
        
        } else if (escolha == 3) {
            atualizarFuncionarioInsertion(&funcionarios, &qttFuncionarios);
            
        } else if (escolha == 4) {
            deletarFuncionarioInsertion(&funcionarios, &qttFuncionarios);

        } else if (escolha == 8) {
            puts("VOLTANDO......");
            break;
        }
    }
    
}