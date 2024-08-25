#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../includes/insertionSortHeader.h"
#include "../includes/geradorCargaInsertion.h"

// Função para gerar um nome aleatório
void gerarNome(struct FuncionariosInsertion* funcionario, int tamanhoMin, int tamanhoMax) {
const char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    int tamanhoNome = tamanhoMin + rand() % (tamanhoMax - tamanhoMin + 1);
    int tamAlfabeto = sizeof(alfabeto) - 1;

    // Gera um nome aleatório de tamanho variável
    for (int i = 0; i < tamanhoNome; i++) {
        funcionario->nome[i] = alfabeto[rand() % tamAlfabeto];
    }

    funcionario->nome[tamanhoNome] = '\0';  // Finaliza a string com o caractere nulo
}

// Função para gerar um salário aleatório
int gerarSalario(struct FuncionariosInsertion* funcionario, int min, int max) {
    int novoSalario = min + rand() % (max - min + 1);

    funcionario->salario = novoSalario;
}

void geradorCarga(int carga, struct FuncionariosInsertion** novoFuncionario, int* qttFuncionario) {
    srand(time(NULL));

    int numNomes = 0;          // Número de nomes a serem gerados
    int tamanhoMinNome = 0;    // Tamanho mínimo de cada nome
    int tamanhoMaxNome = 0;    // Tamanho máximo de cada nome
    int salarioMin = 0;        // Salário mínimo
    int salarioMax = 0;        // Salário máximo

    switch (carga) {
        case 1:
            numNomes = 100;
            tamanhoMinNome = 1;
            tamanhoMaxNome = 100;
            salarioMin = 1;
            salarioMax = 100;
            break;

        case 2:
            numNomes = 1000;
            tamanhoMinNome = 1;
            tamanhoMaxNome = 1000;
            salarioMin = 1;
            salarioMax = 1000;
            break;

        case 3:
            numNomes = 10000;
            tamanhoMinNome = 1;
            tamanhoMaxNome = 10000;
            salarioMin = 1;
            salarioMax = 10000;
            break;

        case 4:
            numNomes = 100000;
            tamanhoMinNome = 1;
            tamanhoMaxNome = 100000;
            salarioMin = 1;
            salarioMax = 100000;
            break;

        case 5:
            numNomes = 1000000;
            tamanhoMinNome = 1;
            tamanhoMaxNome = 1000000;
            salarioMin = 1;
            salarioMax = 1000000;
            break;
        
        default:
            break;
    }

    int qtdAtual = *qttFuncionario;
    *qttFuncionario += numNomes;
    alocarFuncionarioInsertion(novoFuncionario, qttFuncionario);

    for (int i = qtdAtual; i < *qttFuncionario; i++) {
        gerarNome(&(*novoFuncionario)[i], tamanhoMinNome, tamanhoMaxNome); // Gera o nome de tamanho variável

        gerarSalario(&(*novoFuncionario)[i], salarioMin, salarioMax); // Gera o salário

        printf("gerando: ");
        printf("%i ", i);
    }
    puts("");

    printf("Nomes e salários gerados foram exibidos no terminal.\n");
}
