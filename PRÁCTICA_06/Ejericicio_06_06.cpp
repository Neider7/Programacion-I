// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 19/05/2024
// Fecha modificación: 19/05/2024
// Número de ejercicio: 6
// Problema planteado: Realizar un algoritmo recursivo para la siguiente función
// Q(n)= 1^^2+...+n^^2...

#include <iostream>

using namespace std;

int funcion_Q(int n);
int main() 
{
    int n;
    cout << "Ingrese un valor para n: ";
    cin >> n;
    int resultado = funcion_Q(n);
    cout << "Q(" << n << ") = " << resultado << endl;
    return 0;
}
// Función recursiva para calcular Q(n)
int funcion_Q(int n)
{
    if (n == 0) 
    {
        return 0;
    }
    return funcion_Q(n - 1) + n * n;
}