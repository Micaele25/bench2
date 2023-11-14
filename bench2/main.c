#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "classificacao.h"
#include "calculo.h"

void gerarNumerosAleatorios(const char *nomeArquivo, int quantidade);

int *lerNumerosDoArquivo(const char *nomeArquivo, int *tamanho);

int main() {
    const char *nomeArquivo = "numeros.txt";
    int qtdGerada;
    int opcao = 0;
    int qtdLida = 0;
    int *numeros;

    printf("Digite a quantidade de números a serem gerados: ");
    scanf("%d", &qtdGerada);

    gerarNumerosAleatorios(nomeArquivo, qtdGerada);

    printf("Números gerados e salvos no arquivo: %s\n", nomeArquivo);

    numeros = lerNumerosDoArquivo(nomeArquivo, &qtdLida);

    while (opcao != 4) {
        // Apresente o menu para o usuário
        printf("Escolha uma opção:\n");
        printf("1. Busca de elemento\n");
        printf("2. Classificação de elementos\n");
        printf("3. Operações de cálculo\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        int numero;
        double tempo;

        switch (opcao) {
            case 1:
                printf("Digite o número a ser buscado: ");
                scanf("%d", &numero);

                tempo = buscaLinear(numeros, qtdLida, numero);
                printf("Tempo da busca linear: %f segundos\n", tempo);

                tempo = buscaBinaria(numeros, qtdLida, numero);
                printf("Tempo da busca binária: %f segundos\n", tempo);

                break;

            case 2:
                bubbleSort(numeros, qtdLida);

                printf("Números ordenados:\n");
                for (int i = 0; i < qtdLida; i++) {
                    printf("%d ", numeros[i]);
                }
                printf("\n");

                break;

            case 3:
                int n;
                printf("Digite o valor para operações de cálculo: ");
                scanf("%d", &n);

                int resultadoFatorial = fatorial(n);
                printf("O fatorial de %d é %d\n", n, resultadoFatorial);

                int resultadoFibonacci = fibonacci(n);
                printf("O termo %d da sequência de Fibonacci é %d\n", n, resultadoFibonacci);

                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida\n");
        }
    }

    free(numeros);

    return 0;
}

void gerarNumerosAleatorios(const char *nomeArquivo, int quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
        int numero = rand() % 1000 + 1;
        fprintf(arquivo, "%d ", numero);
    }

    fclose(arquivo);
}


int* lerNumerosDoArquivo(const char *nomeArquivo, int *tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    int capacidade = 10; // Tamanho inicial para alocar memória
    int *numeros = (int *)malloc(capacidade * sizeof(int));
    if (numeros == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    int numero;
    *tamanho = 0;
    while (fscanf(arquivo, "%d", &numero) == 1) {
        if (*tamanho == capacidade) {
            capacidade *= 2; // Dobra a capacidade ao atingir o limite
            numeros = realloc(numeros, capacidade * sizeof(int));
            if (numeros == NULL) {
                perror("Erro ao realocar memória");
                exit(EXIT_FAILURE);
            }
        }
        numeros[*tamanho] = numero;
        (*tamanho)++;
    }

    fclose(arquivo);
   return NULL;
}
