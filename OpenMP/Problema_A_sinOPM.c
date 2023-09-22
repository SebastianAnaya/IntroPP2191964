#include <stdio.h>
#include <time.h>

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
    int contador = 0;
    int i = 1;  // Iniciar en el primer índice par (0) de Fibonacci

    clock_t inicio, fin;
    double tiempo;

    inicio = clock(); // Registra el tiempo de inicio
    
    // Calcular la suma de los primeros N términos pares de Fibonacci
    while (contador < N) {
        unsigned long long numero = fibonacci(i);
        suma += numero;
        contador++;
        i += 2;  // Pasar al siguiente índice par de Fibonacci
    }

    fin = clock(); // Registra el tiempo de finalización

    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("La suma de los primeros %d términos pares de Fibonacci es: %llu\n", N, suma);
    printf("Tiempo de ejecución: %f segundos\n", tiempo);

    return 0;
}

