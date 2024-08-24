#include <stdio.h>
#include "./includes/menus.h"
#include "./includes/insertionSortHeader.h"
#include "./includes/selectionSortHeader.h"

int main() {
    int escolha = menuPrincipal();

    if (escolha == 6)
        insertionSort();
    else if (escolha == 7)
        selectionSort();

    return 0;
}