import time

def sum_vec(arr):
    soma = 0
    for val in arr:
        soma += val
    return soma

tamanhos = [100, 1000, 10000]

print("--- Resultados em Python (perf_counter_ns - Nanossegundos) ---")

for n in tamanhos:
    vetor = [1] * n # Cria um vetor de tamanho 'n' preenchido com '1'
    
    print(f"\nTamanho do Vetor: {n}")
    
    for iteracao in range(1, 11):
        
        # Inicia o cronômetro de performance
        start = time.perf_counter_ns() 
        
        resultado = sum_vec(vetor) # Executa
        
        # Para o cronômetro
        end = time.perf_counter_ns() 
        
        tempo_ns = end - start
        
        print(f"Iteracao {iteracao:02d}: {tempo_ns} ns")