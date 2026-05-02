#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que soma o vetor
long long sum_vec(int *arr, int n) {
    long long soma = 0;
    for (int i = 0; i < n; i++) {
        soma += arr[i];
    }
    return soma;
}

int main() {
    int tamanhos[] = {100, 1000, 10000};
    int num_tamanhos = 3;
    struct timespec start, end;

    printf("--- Resultados em C (Nanossegundos) ---\n");

    for (int t = 0; t < num_tamanhos; t++) {
        int n = tamanhos[t];
        
        // Cria e preenche o vetor com o número 1
        int *vetor = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) vetor[i] = 1;

        printf("\nTamanho do Vetor: %d\n", n);
        
        for (int iteracao = 1; iteracao <= 10; iteracao++) {
            
            // Inicia o cronômetro de alta precisão
            clock_gettime(CLOCK_MONOTONIC, &start);
            
            long long resultado = sum_vec(vetor, n); // Executa
            
            // Para o cronômetro
            clock_gettime(CLOCK_MONOTONIC, &end);

            // Calcula a diferença exata em nanossegundos
            long long tempo_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
            
            printf("Iteracao %02d: %lld ns\n", iteracao, tempo_ns);
        }
        free(vetor);
    }
    return 0;
}