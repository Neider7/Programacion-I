// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 23/05/2024
// Fecha modificación: 23/05/2024
// Número de ejercicio: 3
// Problema planteado: 3 Escribir un programa que escriba la lista de caracteres ASCII dentro de un archivo de texto

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    system("cls");
    int valor;
    cout << "Introduce un numero para mostrar caracteres ASCII (debe ser >= 32 y <= 255): ";
    cin >> valor;
    if (valor < 32 || valor > 255) 
    {
        cerr << "Error: El valor debe estar entre 32 y 255." << endl;
        return 1;
    }
    // Abrir el archivo de destino para escritura
    ofstream salida("caracteres_ASCII.txt");
    if (!salida.is_open()) 
    {
        cout << "Error al abrir el archivo de destino: caracteres_ASCII.txt" << endl;
        return 1;
    }
    for (int i = 32; i <= valor; i++) 
    {
        salida << "Caracter: " << char(i) << "  Codigo ASCII: " << i << endl;
    }
    salida.close();
    cout << "Los caracteres ASCII han sido guardados en caracteres_ASCII.txt" << endl;
    return 0;
}

