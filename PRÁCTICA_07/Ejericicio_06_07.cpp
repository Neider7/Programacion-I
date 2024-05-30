// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 27/05/2024
// Número de ejercicio: 6
// Problema planteado: 6 Crear un programa donde se introduzca un número para luego convertirlo en base 6,8, 10

#include <iostream>
#include <string>
using namespace std;

// Función para convertir un numero a una base especifica
string convertirBase(int numero, int base) 
{
    if (numero == 0) 
    return "0";
    string resultado = "";
    int temp = numero;
    while (temp > 0) 
    {
        int residuo = temp % base;
        resultado = char((residuo < 10 ? '0' + residuo : 'A' + (residuo - 10))) + resultado;
        temp /= base;
    }
    return resultado;
}
int main() 
{
    int numero;
    cout << "Introduce un numero: ";
    cin >> numero;
    if (numero < 0) 
    {
        cerr << "Error: Introduzca un nnmero no negativo." << endl;
        return 1;
    }
    // Convertir el numero a las diferentes bases
    string base6 = convertirBase(numero, 6);
    string base8 = convertirBase(numero, 8);
    string base10 = convertirBase(numero, 10);
    
    cout << "El numero en base 6 es: " << base6 << endl;
    cout << "El numero en base 8 es: " << base8 << endl;
    cout << "El numero en base 10 es: " << base10 << endl;
    return 0;
}
