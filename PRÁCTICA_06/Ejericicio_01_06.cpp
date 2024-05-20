// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 15/05/2024
// Fecha modificación: 18/05/2024
// Número de ejercicio: 1
// Problema planteado: 1. Realizar un algoritmo recursivo para calcular el máximo común divisor de dos
// números enteros aplicando el algoritmo de Euclides.

#include <iostream>
using namespace std;

int funcion(int a, int b);
int main() 
{
    int numero1, numero2; 
    cout << "Introduce el primer numero: ";
    cin >> numero1;  
    cout << "Introduce el segundo numero: ";
    cin >> numero2;  
    int resultado = funcion(numero1, numero2);
    cout << "El valor medio de :" << numero1 << " y " << numero2 << " es: " << resultado << endl;
    return 0;
}
// Función recursiva para calcular
int funcion(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    } else {
        return funcion(b, a % b);
    }
}
