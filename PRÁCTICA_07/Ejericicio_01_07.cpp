// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 23/05/2024
// Fecha modificación: 23/05/2024
// Número de ejercicio: 1
// Problema planteado: 1 Escribir un programa que escriba “hola mundo” dentro de un archivo llamado hola.txt.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    system("cls");
    ofstream salida;
    salida.open("hola.txt");
    salida << "hola mundo";
    salida.close();   
    return 0;
}