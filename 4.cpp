#include <iostream>

using namespace std;

// Función que intercambia dos valores
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función que invierte el array y verifica si p es impar para hacer el intercambio
void split(int* p, int* q) {
    while (p < q) {
        // Verificar si el valor de p es impar
        if (*p % 2 != 0) {
            // Intercambiamos el valor de p con q
            swap(p, q);
            // Movemos q hacia la izquierda
            q--;
        }
        // Siempre avanzamos p hacia adelante
        p++;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Ejecutar la función split
    split(arr, arr + n - 1);

    cout << "Array transformado:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
