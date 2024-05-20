// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 19/05/2024
// Fecha modificación: 20/05/2024
// Número de ejercicio: 10
// Problema planteado: Realizar un algoritmo recursivo para calcular el coeficiente binomial a partir de
// la lectura de dos números enteros, a partir de la relación:

#include <iostream>
using namespace std;

int coeficienteBinomial(int n, int k);

int main() 
{
    int n, k;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "Ingrese el valor de k: ";
    cin >> k;
    int resultado = coeficienteBinomial(n, k);
    // Mostrar el resultado
    cout << "El coeficiente binomial C(" << n << ", " << k << ") es: " << resultado << endl;
    return 0;
}
int coeficienteBinomial(int n, int k) 
{
    if (k == 0 || k == n) 
    {
        return 1;
    }
    if (k > n) 
    {
        return 0;
    }
    return coeficienteBinomial(n - 1, k - 1) + coeficienteBinomial(n - 1, k);
}
