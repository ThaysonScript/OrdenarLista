#include <stdio.h>
#include "./includes/menus.h"
#include "./includes/insertionSortHeader.h"
#include "./includes/selectionSortHeader.h"

int main() {
    while (1) {
        int algoritmo = escolherAlgoritmo();

        if (algoritmo == 1)
            insertionSort();
        else if (algoritmo == 2)
            selectionSort();
        else if (algoritmo == 3)
            break;
        else
            printf("ERRO: EXECUTE CORRETAMENTE A ESCOLHA");
    }
    puts("FINALIZADO!!!!");

    return 0;
}