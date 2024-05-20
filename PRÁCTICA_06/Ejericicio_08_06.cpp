// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 19/05/2024
// Fecha modificación: 19/05/2024
// Número de ejercicio: 8
// Problema planteado: Realizar un algoritmo recursivo que nos diga si una cadena de caracteres es
// simétrica

#include <iostream>
#include <string>

using namespace std;
bool esSimetrica(const string& str, int inicio, int fin);

int main() 
{
    string cadena;
    cout << "Introduce una cadena: ";
    getline(cin, cadena);

    if (esSimetrica(cadena, 0, cadena.length() - 1)) 
    {
        cout << "La cadena es simetrica." << endl;
    } else 
    {
        cout << "La cadena no es simetrica." << endl;
    }
    return 0;
}
// Función recursiva para verificar si una cadena es simétrica
bool esSimetrica(const string& str, int inicio, int fin) 
{
    if (inicio >= fin) {
        return true;
    }
    if (str[inicio] != str[fin])
    {
        return false;
    }
    return esSimetrica(str, inicio + 1, fin - 1);
}