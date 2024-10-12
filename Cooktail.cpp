#include <iostream>
using namespace std;
void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void cocktailSort(int* inicio, int* fin) {
    bool swapped = true;
    while (swapped) {
        swapped = false;

        // Recorrido de izquierda a derecha
        int* ptr = inicio; 
        while ((ptr < fin)) { //revisa si ptr tiene elementos que revisar mientras sea menor que la pos final
            cout <<"izquierda a derecha: " << *ptr << " " << *inicio << " " << *fin << endl;
            if (*ptr > *(ptr + 1)) {
                swap(*ptr, *(ptr + 1));
                swapped = true;
            }
            ptr++; //actualiza la pos del puntero ptr
        }

        // Si no hubo intercambios, el arreglo ya está ordenado
        if (!swapped)
            break;

        // Decrementa el puntero al final porque el elemento más grande ya está en su posición correcta
        fin--;

        // Recorrido de derecha a izquierda
        ptr = fin;
        while (ptr >= inicio) { // revisa si ptr tiene elementos que revisar mientras que sea mayor o igual que la pos inicial
            cout << "derecha a izquierda: " << *ptr << " " << *inicio << " " << *fin << endl;
            if (*ptr < *(ptr - 1)) {
                swap(*ptr, *(ptr - 1));
                swapped = true;
            }
            ptr--;
        }

        // Incrementa el puntero de inicio porque el elemento más pequeño ya está en su posición correcta
        inicio++;
    }
}

bool busqueda_binaria(int* inicio, int* fin, int*& pos, int key) {
    int* izquierda = inicio;
    int* derecha = fin - 1;
    while (izquierda <= derecha) { //mientras que el puntero izquiera sea menos o igual a derecha se ejecuta el bloque de codigo
        int* pivote = izquierda + (derecha - izquierda) / 2; //operacion para calcular el medio
        if (*pivote == key) {//este if comprueba se el valor digitado se encontro en el medio
            pos = pivote;
            return true;
        }
        else if (*pivote > key) { //si el valor digitado no se encontro en el medio, aqui evalua si el valor es menor que el elemento del medio, para asi dividir el array y reducir el coste computacional
            derecha = pivote - 1;
        }
        else {
            izquierda = pivote + 1;
        }
    }
    pos = nullptr;
    return false;
}

int main() {
	int arr[] = { 15, 2, 16, 3, 8, 9, 11, 17, 26, 13, 24 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Arreglo original: ";
	for (int* i = arr; i < arr + n ; i++) {
		cout << *i << " ";
	}
	cout << endl;

	cocktailSort(arr, arr + n - 1);

	cout << "Arreglo ordenado: ";
	for (int* i = arr; i < arr + n; i++) {
		cout << *i << " ";
	}
	cout << endl;
    int* inicio = &arr[0];
    int* final = &arr[n];
    int* pos = nullptr;
    int key;
    cout << "Ahora que elemento desea buscar?: ";
    cin >> key;
    bool comprobar = busqueda_binaria(inicio, final, pos, key); 
    
    if (comprobar) {
        cout << "El elemento buscado: " << key << " fue encontrado en la posicion " << (pos - inicio) << endl;
    }
    
    else {
        cout << "El elemento buscado: " << key << " no fue encontrado" << endl;
    }
	return 0;
}