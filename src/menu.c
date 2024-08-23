#include <stdio.h>

int menu() {
    puts("---------------- Gerenciar Funcionarios --------------");
    puts("--------- C.R.U.D");
    puts("[1] - Criar Funcionarios");
    puts("[2] - Ler Funcionarios");
    puts("[3] - Atualizar Funcionarios");
    puts("[4] - Deletar Funcionarios");
    puts("");
    puts("--------- ORDENACAO");
    puts("[5] - Inserction Sort");
    puts("[6] - Selection Sort");

    int escolha;
    printf("Escolha a entrada: ");
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
    
        default:
            puts("invalido ou desejou sair");
            break;
    }
}