#include <stdio.h>
#include "src/menu.c"
#include "src/inserctionSort.c"
#include "src/selectionSort.c"

int main() {
    int escolha = menu();

    if (escolha == 5)
        inserctionSort();
    else if (escolha == 6)
        selectionSort();

    return 0;
}