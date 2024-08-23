#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um nome aleatório
void gerar_nome(int tamanho_do_nome, FILE *arquivo) {
    const char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    int tamanho_alfabeto = sizeof(alfabeto) - 1;

    for (int i = 0; i < tamanho_do_nome; i++) {
        char letra = alfabeto[rand() % tamanho_alfabeto];
        printf("%c", letra);
        fprintf(arquivo, "%c", letra);
    }
}

// Função para gerar um salário aleatório
int gerar_salario(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL));

    int num_nomes = 10;          // Número de nomes a serem gerados
    int tamanho_do_nome = 6;     // Tamanho de cada nome
    int salario_min = 1000;      // Salário mínimo
    int salario_max = 10000;     // Salário máximo

    // Abre o arquivo para escrita
    FILE *arquivo = fopen("nomes_e_salarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    for (int i = 0; i < num_nomes; i++) {
        gerar_nome(tamanho_do_nome, arquivo); // Gera o nome e escreve no arquivo
        int salario = gerar_salario(salario_min, salario_max); // Gera o salário
        printf(" - Salário: R$%d\n", salario);
        fprintf(arquivo, " - Salário: R$%d\n", salario); // Escreve o salário no arquivo
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Nomes e salários gerados foram salvos em 'nomes_e_salarios.txt'.\n");

    return 0;
}
