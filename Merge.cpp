#include <iostream>
using namespace std;

void merge(int* arr, int ini, int mid, int fin) {
    int tam1 = mid - ini + 1;
    int tam2 = fin - mid;
    int* izq = new int[tam1];
    int* der = new int[tam2];
    for (int i = 0; i < tam1; i++)
        *(izq+i) = *(arr+(ini + i));
    for (int j = 0; j < tam2; j++)
        *(der+j) = *(arr+(mid + 1 + j));
    int i = 0, j = 0;
    int k = ini;
    while (i < tam1 && j < tam2) {
        if (*(izq+i) <= *(der+j)) {
            *(arr+k) = *(izq+i);
            i++;
        } else {
            *(arr+k) = *(der+j);
            j++;
        }
        k++;
    }
    while (i < tam1) {
        *(arr+k) = *(izq+i);
        i++;
        k++;
    }
    while (j < tam2) {
        *(arr+k) = *(der+j);
        j++;
        k++;
    }
    delete[] izq;
    delete[] der;
}

void msort(int* arr, int ini, int fin) {
    if (ini < fin) {
        int mid = ini + (fin - ini) / 2;
        msort(arr, ini, mid);
        msort(arr, mid + 1, fin);
        merge(arr, ini, mid, fin);
    }
}

int main() {
    int tam;
    int val;
    cout << "Ingrese el tamaño del array: ";
    cin >> tam;
    int* arr = new int[tam];
    cout << "Ingrese los elementos del array: " << endl;
    for (int i = 0; i < tam; i++) {
        cin >> val;
        *(arr + i) = val;
    }
    cout << "Array sin ordenar: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    msort(arr, 0, tam - 1);
    cout << "Array ordenado: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0; 
        }