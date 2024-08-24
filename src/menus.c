#include <stdio.h>
#include "../includes/menus.h"

int menuPrincipal() {
    puts("\t\t\t\t\t\t---------------- GERENCIAR FUNCIONARIOS --------------");
    puts("\t\t\t\t\t\t--------- C.R.U.D");
    puts("\t\t\t\t\t\t[1] - CRIAR FUNCIONARIO");
    puts("\t\t\t\t\t\t[2] - LER FUNCIONARIO");
    puts("\t\t\t\t\t\t[3] - ATUALIZAR FUNCIONARIO");
    puts("\t\t\t\t\t\t[4] - DELETAR FUNCIONARIO");
    puts("");
    puts("\t\t\t\t\t\t-------- DADOS DE DESEMPENHO DE ALGORITMO");
    puts("\t\t\t\t\t\t[5] - REALIZAR PRE DADOS");
    puts("");
    puts("\t\t\t\t\t\t--------- ORDENACAO");
    puts("\t\t\t\t\t\t[6] - INSERTION SORT");
    puts("\t\t\t\t\t\t[7] - SELECTION");
    puts("\t\t\t\t\t\t------------------------------------------------------");

    int escolha;
    printf("\t\t\t\t\t\tEscolha a entrada: ");
    scanf("%i", &escolha);

    switch (escolha) {
        case 1:
            puts("escolheu 1");
            return escolha;

        case 2:
            puts("escolheu 2");
            return escolha;

        case 3:
            puts("escolheu 3");
            return escolha;

        case 4:
            puts("escolheu 4");
            return escolha;

        case 5:
            puts("escolheu 5");
            return escolha;

        case 6:
            puts("escolheu 6");
            return escolha;

        case 7:
            puts("escolheu 7");
            return escolha;
    
        default:
            puts("invalido ou desejou sair");
            break;
    }
}

int desejaGerarDados() {
    int gerar;

    puts("\t\t\t\t\t\t-------------- DESEJA GERAR DADOS PRE CADASTRADOS? ---------------");
    puts("\t\t\t\t\t\t[1] - GERAR 100 DE DADOS ALEATORIOS");
    puts("\t\t\t\t\t\t[2] - GERAR 1.000 DE DADOS ALEATORIOS");
    puts("\t\t\t\t\t\t[3] - GERAR 10.000 DE DADOS ALEATORIOS");
    puts("\t\t\t\t\t\t[4] - GERAR 100.000 DE DADOS ALEATORIOS");
    puts("\t\t\t\t\t\t[5] - GERAR 1.000.000 DE DADOS ALEATORIOS");
    puts("\t\t\t\t\t\t[6] - NAO GERAR DADOS ALEATORIOS");
    puts("\t\t\t\t\t\t------------------------------------------------------");

    printf("\t\t\t\t\t\tEscolha a entrada: ");
    scanf("%i", &gerar);

    while (1) {
        switch (gerar) {
            case 1:
            puts("escolheu 1");
            return gerar;

        case 2:
            puts("escolheu 2");
            return gerar;

        case 3:
            puts("escolheu 3");
            return gerar;

        case 4:
            puts("escolheu 4");
            return gerar;

        case 5:
            puts("escolheu 5");
            return gerar;

        case 6:
            puts("escolheu 6");
            return gerar;

            default:
                gerar = 0;
                return gerar;
        }

        
    }
}