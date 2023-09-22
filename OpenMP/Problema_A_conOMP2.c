#include <stdio.h>
#include <omp.h>

// Función para calcular el número de Fibonacci en la posición n
unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        unsigned long long a = 0, b = 1, temp;
        for (int i = 2; i <= n; i++) {
            temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
}

int main() {
    int N;
    printf("Ingrese el valor de N (número de términos pares de Fibonacci a sumar): ");
    scanf("%d", &N);

    unsigned long long suma = 0;
    double start_time, end_time;

    start_time = omp_get_wtime(); // Registra el tiempo de inicio

    #pragma omp parallel
    {
        unsigned long long local_suma = 0;
        #pragma omp for
        for (int i = 1; i <= 2 * N - 1; i += 2) {
            unsigned long long numero = fibonacci(i);
            local_suma += numero;
        }

        #pragma omp critical
        {
            suma += local_suma;
        }
    }

    end_time = omp_get_wtime(); // Registra el tiempo de finalización

    printf("La suma de los primeros %d indices pares de la serie Fibonacci es: %llu\n", N, suma);
    printf("Tiempo de ejecución: %f segundos\n", end_time - start_time);

    return 0;
}

