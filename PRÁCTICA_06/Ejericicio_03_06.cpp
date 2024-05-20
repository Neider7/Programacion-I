// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 15/05/2024
// Fecha modificación: 18/05/2024
// Número de ejercicio: 3
// Problema planteado: Realizar un algoritmo recursivo, dado un vector de números enteros, retorne la
// suma de sus elementos.

#include <iostream>
#include <vector>

using namespace std;
int sumaVector(const vector<int>& valores, int n);
int main() 
{
    int n;  
    cout << "Introduce el numero de elementos del vector: ";
    cin >> n;
    vector<int> valores(n);
    cout << "Introduce los elementos del vector: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> valores[i];
    }
    int suma = sumaVector(valores, n);
    cout << "La suma de los elementos del vector es: " << suma << endl;
    return 0;
}
// Función recursiva para sumar los elementos de un vector
int sumaVector(const vector<int>& valores, int n) 
{
    if (n == 0) 
    {
        return 0;
    }
    return valores[n - 1] + sumaVector(valores, n - 1);
}

