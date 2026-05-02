public class SomaVetorNano {
    
    public static long sumVec(int[] arr) {
        long soma = 0;
        for (int val : arr) {
            soma += val;
        }
        return soma;
    }

    public static void main(String[] args) {
        int[] tamanhos = {100, 1000, 10000};
        
        System.out.println("--- Resultados em Java (System.nanoTime - Nanossegundos) ---");

        for (int n : tamanhos) {
            int[] vetor = new int[n];
            for (int i = 0; i < n; i++) vetor[i] = 1; // Preenche com 1

            System.out.println("\nTamanho do Vetor: " + n);
            
            for (int iteracao = 1; iteracao <= 10; iteracao++) {
                
                // Inicia o cronômetro do hardware via JVM
                long start = System.nanoTime(); 
                
                long resultado = sumVec(vetor); // Executa
                
                // Para o cronômetro
                long end = System.nanoTime(); 
                
                long tempoNano = end - start;
                System.out.println("Iteracao " + String.format("%02d", iteracao) + ": " + tempoNano + " ns");
            }
        }
    }
}