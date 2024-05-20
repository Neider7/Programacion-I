// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 15/05/2024
// Fecha modificación: 18/05/2024
// Número de ejercicio: 4
// Problema planteado: Realizar un algoritmo recursivo que escriba al revés una cadena.

#include <iostream>
#include <string>

using namespace std;

void invertirCadena(string& str, int inicio, int fin);
int main() 
{
    string cadena;
    cout << "Introduce una cadena: ";
    getline(cin, cadena);
    // invertir la cadena
    invertirCadena(cadena, 0, cadena.length() - 1);
    cout << "La cadena invertida es: " << cadena << endl;
    return 0;
}
// Función recursiva para invertir una cadena
void invertirCadena(string& str, int inicio, int fin) 
{
    if (inicio >= fin) 
    {
        return;
    }
    swap(str[inicio], str[fin]);
    invertirCadena(str, inicio + 1, fin - 1);
}