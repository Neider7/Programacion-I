// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 23/05/2024
// Fecha modificación: 23/05/2024
// Número de ejercicio: 2
// Problema planteado: 2 Escribir un programa que lea el archivo creado en el ejercicio anterior y muestre por pantalla su 
// contenido.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    system("cls");
    ifstream entrada;
    entrada.open("hola.txt");
    string texto;  
    getline(entrada,texto);
    cout << texto << endl;
    entrada.close();
    return 0;
}
