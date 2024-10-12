#include <iostream>

using namespace std;


void merge(int* p, int* q, int* r) {
    int n1 = q - p + 1; 
    int n2 = r - q;     

    int* L = new int[n1];
    int* R = new int[n2];


    for (int i = 0; i < n1; i++)
        L[i] = *(p + i);
    for (int i = 0; i < n2; i++)
        R[i] = *(q + 1 + i);


    int i = 0, j = 0;
    int* k = p;


    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            *k = L[i];
            i++;
        } else {
            *k = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        *k = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        *k = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}


void mergeSort(int* p, int* r) {
    if (p < r) {
        int* q = p + (r - p) / 2;  

        mergeSort(p, q);
        mergeSort(q + 1, r);
        merge(p, q, r);
    }
}

int main() {
    int arr[] = {6,3,100,50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, arr + n - 1);

    cout << "Array ordenado:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
