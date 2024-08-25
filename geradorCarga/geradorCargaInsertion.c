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

    int numNomes = 0;           // qtd de nomes gerados
    int tamanhoMinNome = 1;     // caractere minimo de nome
    int tamanhoMaxNome = 100;   // caractere maximo de nome
    int salarioMin = 0;         // salario minimo
    int salarioMax = 100000;    // salario maximo

    switch (carga) {
        case 1: numNomes = 100; break;
        case 2: numNomes = 1000; break;
        case 3: numNomes = 10000; break;
        case 4: numNomes = 100000; break;
        case 5: numNomes = 1000000; break;
        default: puts("Carga inválida."); return;
    }

    int qtdAtual = *qttFuncionario;
    *qttFuncionario += numNomes;
    alocarFuncionarioInsertion(novoFuncionario, qttFuncionario);

    for (int i = qtdAtual; i < *qttFuncionario; i++) {
        gerarNome(&(*novoFuncionario)[i], tamanhoMinNome, tamanhoMaxNome); // gera o nome com um tamanho para cada funcionario

        gerarSalario(&(*novoFuncionario)[i], salarioMin, salarioMax); // Gera o salario para cada funcionario

        printf("gerando: ");
        printf("%i ", i);
    }
    puts("");

    printf("Nomes e salários gerados foram exibidos no terminal.\n");
}
