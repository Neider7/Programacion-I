// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 23/05/2024
// Fecha modificación: 23/05/2024
// Número de ejercicio: 4
// Problema planteado: 4 Escribir un programa que lea y muestre en pantalla el archive generado en el ejercicio anterior

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    system("cls");
    ifstream caracteres;
    caracteres.open("caracteres_ASCII.txt");
    string texto;
    while (!caracteres.eof())
    {
        getline(caracteres,texto);
        cout <<texto<<endl;
    }
    caracteres.close();

    return 0;
}