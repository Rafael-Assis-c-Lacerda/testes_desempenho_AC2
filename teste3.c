#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para criar o arquivo "pesado" de 50 MB
void criar_arquivo_50mb() {
    FILE *f = fopen("teste_gzip.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar o arquivo de teste!\n");
        return;
    }
    // Criando um buffer de 1MB para escrever 50 vezes (50 MB)
    char *buffer = (char *)malloc(1024 * 1024);
    for(int i = 0; i < 50; i++) {
        fwrite(buffer, 1, 1024 * 1024, f);
    }
    free(buffer);
    fclose(f);
}

int main() {
    clock_t start, end;
    double tempo_gcc, tempo_gzip;

    printf("Preparando ambiente para o benchmark...\n");

    // --- 1. Benchmark do GCC ---
    printf("Criando codigo fonte para o GCC...\n");
    FILE *f_c = fopen("codigo_teste.c", "w");
    fprintf(f_c, "#include <stdio.h>\nint main() { printf(\"Teste SPEC\"); return 0; }\n");
    fclose(f_c);

    printf("Executando GCC...\n");
    start = clock();
    system("gcc codigo_teste.c -o codigo_teste.exe");
    end = clock();
    tempo_gcc = ((double)(end - start)) / CLOCKS_PER_SEC;

    // --- 2. Benchmark do GZIP ---
    printf("Criando arquivo de 50MB para o GZIP...\n");
    criar_arquivo_50mb();

    printf("Executando GZIP...\n");
    start = clock();
    // Substitua a linha antiga por esta:
    system("tar -czf teste_gzip.tar.gz teste_gzip.dat");
    end = clock();
    tempo_gzip = ((double)(end - start)) / CLOCKS_PER_SEC;

    // --- Resultados ---
    printf("\n========================================\n");
    printf("--- Resultados Computador 3 (O Seu PC) ---\n");
    printf("Tempo de execucao do gcc:  %f segundos\n", tempo_gcc);
    printf("Tempo de execucao do gzip: %f segundos\n", tempo_gzip);
    printf("========================================\n");

    return 0;
}