#include <time.h>
#include "classificacao.h"

void bubbleSort(int *numeros, int tamanho) {
    clock_t inicio = clock();
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
    clock_t fim = clock();
    printf("Tempo do Bubble Sort: %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int *numeros, int inicio, int fim) {
    int pivo = numeros[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (numeros[j] <= pivo) {
            i++;
            trocar(&numeros[i], &numeros[j]);
        }
    }

    trocar(&numeros[i + 1], &numeros[fim]);
    return i + 1;
}

void quickSort(int *numeros, int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(numeros, inicio, fim);
        quickSort(numeros, inicio, p - 1);
        quickSort(numeros, p + 1, fim);
    }
}
