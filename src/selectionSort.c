#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../includes/menus.h"
#include "../includes/selectionSortHeader.h"
#include "../includes/geradorCargaSelection.h"

void limparTelaSelection() {
    system(COMANDO_LIMPAR);
}

void verificarAlocacaoSelection(struct FuncionariosSelection** funcionarioSelection) {
    if (*funcionarioSelection == NULL) {
        puts("OCORREU UM PROBLEMA PARA EXTENDER ESPACO PARA NOVOS FUNCIONARIOS");
        exit(EXIT_FAILURE);

    } else {
        puts("ESPACO DE FUNCIONARIOS REORGANIZADO\n");
    }
}

/** ----------------------------------------------- ALOCAR ESTRUTURA
 * Alocar de forma dinamica a quantidade de estruturas que tiver vontade 
 */
void alocarFuncionarioSelection(struct FuncionariosSelection** novoFuncionario, int* qtdFuncionario) {
    if (*novoFuncionario == NULL) {
        puts("\nINICIALIZANDO CADASTRO DE FUNCIONARIOS");
        *novoFuncionario = (struct FuncionariosSelection*)malloc(*qtdFuncionario * sizeof(struct FuncionariosSelection));
    } else {
        puts("\nREORGANIZANDO ARMAZENAMENTO PARA FUNCIONARIOS");
        struct FuncionariosSelection* temp = realloc(*novoFuncionario, (*qtdFuncionario) * sizeof(struct FuncionariosSelection));
        
        if (temp == NULL) {
            free(*novoFuncionario);
            *novoFuncionario = NULL;
            puts("OCORREU UM PROBLEMA PARA EXTENDER ESPACO PARA NOVOS FUNCIONARIOS");
            exit(EXIT_FAILURE);
        } else {
            *novoFuncionario = temp;
            puts("ESPACO DE FUNCIONARIOS REORGANIZADO\n");
        }
    }

    verificarAlocacaoSelection(novoFuncionario);
}

// ----------------------------------------------- DESALOCAR ESTRUTURA
void desalocarFuncionarioSelection(struct FuncionariosSelection** funcionarios) {
    if (funcionarios != NULL && *funcionarios != NULL) {
        free(*funcionarios);
        *funcionarios = NULL;
    }
}

// ----------------------------------------------- OPERACOES DE C.R.U.D
int criarFuncionarioSelection(struct FuncionariosSelection** novoFuncionario, int* qttFuncionario) {
    limparTelaSelection();
    int tempQtt;
    char novoNome[NOME];
    double novoSalario;

    printf("DESEJA GERAR QUANTOS FUNCIONARIOS: ");
    scanf("%i", &tempQtt);
    getchar();  // limpando buffer de entrada

    *qttFuncionario += tempQtt;

    alocarFuncionarioSelection(novoFuncionario, qttFuncionario);

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

void lerFuncionarioSelection(struct FuncionariosSelection** funcionarios, int* qttFuncionario) {
    printf("QUANTIDADE TOTAL DE FUNCIONARIOS CADASTRADOS: %d\n", *qttFuncionario);

    for (int i = 0; i < *qttFuncionario; i++) {
        printf("----------------- FIXA DO FUNCIONARIO - %i -------------------\n", (i + 1));
        puts("INFORMACOES CADASTRADAS");
        printf("NOME: %s\nSALARIO: %.3lf\n", (*funcionarios)[i].nome, (*funcionarios)[i].salario);
        puts("----------------------------------------------------------------");
    }
}

void atualizarFuncionarioSelection(struct FuncionariosSelection** funcionarios, int* qttFuncionario) {
    limparTelaSelection();
    char nomeFuncionario[NOME], novoNome[NOME];
    double novoSalario;
    int escolha;
    int foiEncontrado = 0;

    puts("---------------------- LISTANDO FUNCIONARIOS ---------------------");
    lerFuncionarioSelection(funcionarios, qttFuncionario);

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

            limparTelaSelection();
            puts("---------------------- LISTANDO FUNCIONARIOS ATUALIZADOS ---------------------");
            lerFuncionarioSelection(funcionarios, qttFuncionario);
            puts("------------------------------------------------------------------------------");
            break;

        }
    }

    if (foiEncontrado == 0)
        puts("FUNCIONARIO NAO FOI ENCONTRADO");
}

void deletarFuncionarioSelection(struct FuncionariosSelection** funcionarios, int* qttFuncionario) {
    limparTelaSelection();
    char nomeFuncionario[NOME];
    int encontrado = 0;

    puts("---------------------- LISTANDO FUNCIONARIOS ---------------------");
    lerFuncionarioSelection(funcionarios, qttFuncionario);

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
            alocarFuncionarioSelection(funcionarios, qttFuncionario);

            printf("FUNCIONARIO { %s } DELETADO\n", nomeFuncionario);

            puts("---------------------- LISTANDO FUNCIONARIOS ATUALIZADOS ---------------------");
            lerFuncionarioSelection(funcionarios, qttFuncionario);
            puts("------------------------------------------------------------------------------");
            break;
        }
    }

    if (encontrado == 0) {
        puts("FUNCIONARIO NÃO ENCONTRADO.");
    }
}

void ordenarPorSelection(struct FuncionariosSelection** funcionarios, int* qttFuncionario) {
    clock_t tempoInicial, tempoFinal; // duas variáveis para guardar o registro clock

    tempoInicial = clock(); // pega esse instante
    printf("tempo antes de ordenar por Selection sort: %.3f\n", (float)tempoInicial);

    // Selection sort para ordenar do maior para o menor
    for (int i = 0; i < *qttFuncionario - 1; i++) {
        // Encontra o índice do maior salário a partir de i até o fim
        int maxIndex = i;
        for (int j = i + 1; j < *qttFuncionario; j++) {
            if ((*funcionarios)[j].salario > (*funcionarios)[maxIndex].salario) {
                maxIndex = j;
            }
        }

        // Troca o maior elemento encontrado com o elemento na posição i
        if (maxIndex != i) {
            struct FuncionariosSelection temp = (*funcionarios)[i];
            (*funcionarios)[i] = (*funcionarios)[maxIndex];
            (*funcionarios)[maxIndex] = temp;
        }
    }

    tempoFinal = clock(); // pega esse
    printf("tempo depois de ordenar por Selection sort: %.3f\n", (float)tempoFinal);

    // tira a diferença e divide por 1000000.0F
    float diferenca = (((float)tempoFinal - (float)tempoInicial) / 1000000.0F ); // mile segundos
    printf("o tempo real que passou para ordenar: %.3f\n",diferenca);
}


// ----------------------------------------------- CHAMADA PRINCIPAL
void selectionSort() {
    limparTelaSelection();

    int qttFuncionarios = 0;
    struct FuncionariosSelection* funcionarios = NULL;

    while (1) {
        int escolha = menuPrincipalSelection();

        if (escolha == 1) {
            criarFuncionarioSelection(&funcionarios, &qttFuncionarios);
            
        } else if (escolha == 2) {
            limparTelaSelection();
            lerFuncionarioSelection(&funcionarios, &qttFuncionarios);
        
        } else if (escolha == 3) {
            atualizarFuncionarioSelection(&funcionarios, &qttFuncionarios);
            
        } else if (escolha == 4) {
            deletarFuncionarioSelection(&funcionarios, &qttFuncionarios);

        } else if (escolha == 5) {
            int carga = desejaGerarDados();

            if (carga >= 1 && carga <= 5) {
                geradorCarga(carga, &funcionarios, &qttFuncionarios);

            } else {
                limparTelaSelection();
                puts("VOLTANDO.......");
            }

        } else if (escolha == 6) {
            ordenarPorSelection(&funcionarios, &qttFuncionarios);

        } else if (escolha == 7) {
            limparTelaSelection();
            puts("VOLTANDO......");
            puts("OS FUNCIONARIOS ARMAZENADOS FORAM PERDIDOS!");
            desalocarFuncionarioSelection(&funcionarios);
            break;
        }
    }
    
}