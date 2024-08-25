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
        puts("OCORREU UM PROBLEMA PARA EXTENDER ESPACO PARA NOVOS FUNCIONARIOS");
        exit(EXIT_FAILURE);

    } else {
        puts("ESPACO DE FUNCIONARIOS REORGANIZADO\n");
    }
}

/** ----------------------------------------------- ALOCAR ESTRUTURA
 * Alocar de forma dinamica a quantidade de estruturas que tiver vontade 
 */
void alocarFuncionarioInsertion(struct FuncionariosInsertion** novoFuncionario, int* qtdFuncionario) {
    if (*novoFuncionario == NULL) {
        puts("\nINICIALIZANDO CADASTRO DE FUNCIONARIOS");
        *novoFuncionario = (struct FuncionariosInsertion*)malloc(*qtdFuncionario * sizeof(struct FuncionariosInsertion));
    } else {
        puts("\nREORGANIZANDO ARMAZENAMENTO PARA FUNCIONARIOS");
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

    printf("DESEJA GERAR QUANTOS FUNCIONARIOS: ");
    scanf("%i", &tempQtt);
    getchar();  // limpando buffer de entrada

    *qttFuncionario += tempQtt;

    alocarFuncionarioInsertion(novoFuncionario, qttFuncionario);

    for (int i = (*qttFuncionario - tempQtt); i < *qttFuncionario; i++) {
        printf("DIGITE O NOME PARA O FUNCIONARIO %i: ", i + 1);
        fgets(novoNome, NOME, stdin);
        novoNome[strcspn(novoNome, "\n")] = '\0';

        strcpy((*novoFuncionario)[i].nome, novoNome);

        printf("DIGITE O SALARIO PARA O FUNCIONARIO %i: ", i + 1);
        scanf("%lf", &novoSalario);
        getchar();

        (*novoFuncionario)[i].salario = novoSalario;
    }

    for (int j = (*qttFuncionario - tempQtt); j < *qttFuncionario; j++) {
        puts("----------------- CADASTRADO -------------------");
        printf("FUNCIONARIO - %i\n", (j + 1));
        puts("INFORMACOES CADASTRADAS:");
        printf("NOME: %s\nSALARIO: %.3lf\n", (*novoFuncionario)[j].nome, (*novoFuncionario)[j].salario);
        puts("------------------------------------------------");
    }
}

void lerFuncionarioInsertion(struct FuncionariosInsertion** funcionarios, int* qttFuncionario) {
    printf("QUANTIDADE TOTAL DE FUNCIONARIOS CADASTRADOS: %d\n", *qttFuncionario);

    for (int i = 0; i < *qttFuncionario; i++) {
        printf("----------------- FIXA DO FUNCIONARIO - %i -------------------\n", (i + 1));
        puts("INFORMACOES CADASTRADAS");
        printf("NOME: %s\nSALARIO: %.3lf\n", (*funcionarios)[i].nome, (*funcionarios)[i].salario);
        puts("----------------------------------------------------------------");
    }
}

void atualizarFuncionarioInsertion(struct FuncionariosInsertion** funcionarios, int* qttFuncionario) {
    limparTela();
    char nomeFuncionario[NOME], novoNome[NOME];
    double novoSalario;
    int escolha;
    int foiEncontrado = 0;

    puts("---------------------- LISTANDO FUNCIONARIOS ---------------------");
    lerFuncionarioInsertion(funcionarios, qttFuncionario);

    puts("---------------------- ATUALIZANDO DADOS ---------------------");
    printf("DIGITE O NOME DO FUNCIONARIO: ");
    fgets(nomeFuncionario, NOME, stdin);
    nomeFuncionario[strcspn(nomeFuncionario, "\n")] = '\0';

    for (int i = 0; i < *qttFuncionario; i++) {
        if (strcmp((*funcionarios)[i].nome, nomeFuncionario) == 0) {
            foiEncontrado = 1;
            printf("FUNCIONARIO COM { %s } ENCONTRADO\n\n", (*funcionarios)[i].nome);

            puts("DESEJA ATUALIZAR O QUE MEU CONSAGRADO?");
            puts("[1] - NOME");
            puts("[2] - SALARIO");
            puts("--------------------------------------------------------------");
            printf("ESCOLHA: ");
            scanf("%i", &escolha);
            getchar();

            if (escolha == 1) {
                printf("DIGITE O NOVO NOME PARA O ANTIGO FUNCIONARIO { %s }: ", (*funcionarios)[i].nome);
                fgets(novoNome, NOME, stdin);
                novoNome[strcspn(novoNome, "\n")] = '\0';

                strcpy((*funcionarios)[i].nome, novoNome);

            } else if (escolha == 2) {
                printf("DIGITE O NOVO SALARIO DO FUNCIONARIO { %s }: ", (*funcionarios)[i].nome);
                scanf("%lf", &novoSalario);
                getchar();

                (*funcionarios)[i].salario = novoSalario;
            }

            limparTela();
            puts("---------------------- LISTANDO FUNCIONARIOS ATUALIZADOS ---------------------");
            lerFuncionarioInsertion(funcionarios, qttFuncionario);
            puts("------------------------------------------------------------------------------");
            break;

        }
    }

    if (foiEncontrado == 0)
        puts("FUNCIONARIO NAO FOI ENCONTRADO");
}

void deletarFuncionarioInsertion(struct FuncionariosInsertion** funcionarios, int* qttFuncionario) {
    limparTela();
    char nomeFuncionario[NOME];
    int encontrado = 0;

    puts("---------------------- LISTANDO FUNCIONARIOS ---------------------");
    lerFuncionarioInsertion(funcionarios, qttFuncionario);

    puts("---------------------- DELETANDO FUNCIONARIO ---------------------");
    printf("DIGITE O NOME DO FUNCIONARIO A SER DELETADO: ");
    fgets(nomeFuncionario, NOME, stdin);
    nomeFuncionario[strcspn(nomeFuncionario, "\n")] = '\0';

    for (int i = 0; i < *qttFuncionario; i++) {
        if (strcmp((*funcionarios)[i].nome, nomeFuncionario) == 0) {
            encontrado = 1;

            // mover funcionários para posição atual
            for (int j = i; j < *qttFuncionario - 1; j++) {
                (*funcionarios)[j] = (*funcionarios)[j + 1];
            }

            *qttFuncionario -= 1;
            alocarFuncionarioInsertion(funcionarios, qttFuncionario);

            printf("FUNCIONARIO { %s } DELETADO\n", nomeFuncionario);

            puts("---------------------- LISTANDO FUNCIONARIOS ATUALIZADOS ---------------------");
            lerFuncionarioInsertion(funcionarios, qttFuncionario);
            puts("------------------------------------------------------------------------------");
            break;
        }
    }

    if (encontrado == 0) {
        puts("FUNCIONARIO NÃO ENCONTRADO.");
    }
}

void ordenarPorInsertion() {
    limparTela();
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
            limparTela();
            lerFuncionarioInsertion(&funcionarios, &qttFuncionarios);
        
        } else if (escolha == 3) {
            atualizarFuncionarioInsertion(&funcionarios, &qttFuncionarios);
            
        } else if (escolha == 4) {
            deletarFuncionarioInsertion(&funcionarios, &qttFuncionarios);

        } else if (escolha == 8) {
            limparTela();
            puts("VOLTANDO......");
            break;
        }
    }
    
}