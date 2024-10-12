#include <iostream>
using namespace std;

void cambio(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int* arr, int tam) {
    for (int i = 0; i < tam; i++) {
        cout << *(arr + i) << " ";
    }
}

void split(int* p, int* q, bool caso, int tamano) {
    int* r = q;
    if (caso) {
        for (int x = 0; x < tamano; x++) { //modificar esto
            if (*p % 2 != 0) {
                cambio(p, r);
                r--;
                while (r != p) {
                    cambio(p, r);
                    r--;
                }
            }
            else {
                p++;
            }
            r = q;
        }
    }
    else {
        for (int x = 0; x < tamano; x++) {
            if (*p % 2 == 0) {
                cambio(p, r);
                r--;
                while (r != p) {
                    cambio(p, r);
                    r--;
                }
            }
            else {
                p++;
            }
            r = q;
        }
    }
}

int main() {
    int tam;
    int val;
    cout<< "Ingrese el tamano del array: ";
    cin>> tam;
    int* arr = new int[tam];
    cout << "Ingrese los elementos del array: " << endl;
    for (int i = 0; i < tam; i++) {
        cin >> val;
        *(arr + i) = val;
    }
    cout << "Array sin ordenar: ";
    print(arr, tam);
    cout << endl;

    split(arr, arr + tam - 1, true, tam);
    cout << "Array (pares, impares): ";
    print(arr, tam);
    cout << endl;

    split(arr, arr + tam - 1, false, tam);
    cout << "Array (impares, pares): ";
    print(arr, tam);
    cout << endl;

    delete[] arr;
    return 0;
}