// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 28/05/2024
// Número de ejercicio: 7
// Problema planteado: 7 Crear un archivo de texto en donde en cada registro se guardan los siguientes datos de un
// estudiante, cada campo se debe separar con el símbolo “;”:
// • Nombre
// • Apellidos
// • Programa académico que estudia
// • Nota del curso

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() 
{
    ofstream archivo("estudiantes.txt", ios::app); 
    if (!archivo.is_open()) 
    {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    string nombre, apellidos, programa;
    double nota;
    // Pedir datos al usuario
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre); 
    cout << "Ingrese los apellidos del estudiante: ";
    getline(cin, apellidos);
    cout << "Ingrese el programa academico que estudia: ";
    getline(cin, programa);
    cout << "Ingrese la nota del curso del estudiante: ";
    cin >> nota;

    // Escribir los datos en el archivo
    archivo << nombre << ";" << apellidos << ";" << programa << ";" << nota << endl;
    archivo.close();
    cout << "Datos guardados correctamente en el archivo" << endl;
    return 0;
}
