#include <iostream>
#include <string>
using namespace std;

string unidades[] = { "", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
string decenas[] = { "", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
string especiales[] = { "diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve" };
string centenas[] = { "", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };

string convertirMenorQueMil(int numero, bool esMiles = false) {
    string resultado = "";

    int centena = numero / 100;
    int resto = numero % 100;

    if (centena > 0) {
        if (centena == 1 && resto == 0) {
            resultado += "cien";
        }
        else {
            resultado += centenas[centena] + " ";
        }
    }

    if (resto >= 10 && resto < 20) {
        resultado += especiales[resto - 10];
    }
    else {
        int decena = resto / 10;
        int unidad = resto % 10;

        if (decena > 0) {
            resultado += decenas[decena];
            if (unidad > 0) {
                resultado += " y " + (unidad == 1 && esMiles ? "un" : unidades[unidad]);
            }
        }
        else {
            resultado += (unidad == 1 && esMiles ? "un" : unidades[unidad]);
        }
    }

    return resultado;
}

string convertirNumero(int numero) {
    if (numero == 0) {
        return "cero";
    }

    string resultado = "";

    int miles = numero / 1000;
    int resto = numero % 1000;

    if (miles > 0) {
        if (miles == 1) {
            resultado += "mil ";
        }
        else {
            resultado += convertirMenorQueMil(miles, true) + " mil ";
        }
    }

    if (resto > 0) {
        resultado += convertirMenorQueMil(resto);
    }

    return resultado;
}

int main() {
    int numero;
    cout << "Ingrese un numero entre 1 y 999999: ";
    cin >> numero;

    if (numero < 1 || numero > 999999) {
        cout << "Número fuera de rango." << endl;
    }
    else {
        cout << convertirNumero(numero) << endl;
    }

    return 0;
}
