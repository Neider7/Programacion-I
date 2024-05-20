// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 19/05/2024
// Fecha modificación: 19/05/2024
// Número de ejercicio: 9
// Problema planteado: Realizar un algoritmo recursivo para Generar la secuencia: 1, 1, 2, 4, 8, 16, 23,
// 28, 38, 49,..., para n términos

#include <iostream>
using namespace std;

// Función recursiva para generar la secuencia
void generarSecuencia(int n, int terminoAnterior = 1, int terminoAnteAnterior = 1, int contador = 2) 
{
    if (contador == n) 
    {
        return;
    }
    int nuevoTermino = terminoAnterior + terminoAnteAnterior + contador;
    cout << nuevoTermino << " ";
    generarSecuencia(n, nuevoTermino, terminoAnterior, contador + 1);
}

int main() 
{
    int n;
    cout << "Ingrese el numero de la secuencia: ";
    cin >> n;
    cout << "La secuencia es: 1 1 ";
    generarSecuencia(n);
    cout << endl;

    return 0;
}
