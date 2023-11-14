#include <time.h>
#include "busca.h"

double buscaLinear(int *numeros, int tamanho, int alvo) {
    clock_t inicio = clock();

    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] == alvo) {
            clock_t fim = clock();
            return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        }
    }

    // Elemento não encontrado
    return -1.0;
}

double buscaBinaria(int *numeros, int tamanho, int alvo) {
    clock_t inicioBuscaBinaria = clock();

    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (numeros[meio] == alvo) {
            clock_t fimBuscaBinaria = clock();
            return ((double)(fimBuscaBinaria - inicioBuscaBinaria)) / CLOCKS_PER_SEC;
        }

        if (numeros[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    // Elemento não encontrado
    return -1.0;
}
