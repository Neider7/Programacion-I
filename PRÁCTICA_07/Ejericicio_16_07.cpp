// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 30/05/2024
// Número de ejercicio: 16
/* Problema planteado: 16 Escribir un programa que genere a partir de un fichero de entrada que contiene una tabla de
números reales otro fichero de salida <nombre>.BIN grabado en formato binario.
Ej:
1.23 3.45 12.5
4.8 3.9 0.83 ........................*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() 
{
    string nombreFicheroEntrada;
    cout << "Ingrese el nombre del fichero de entrada: ";
    cin >> nombreFicheroEntrada;
    ifstream archivoEntrada(nombreFicheroEntrada);
    if (!archivoEntrada.is_open())
    {
        cerr << "No se pudo abrir el archivo de entrada " << nombreFicheroEntrada << endl;
        return 1;
    }
    string nombreFicheroSalida;
    cout << "Ingrese el nombre del fichero de salida (sin extension): ";
    cin >> nombreFicheroSalida;
    nombreFicheroSalida += ".BIN";
    ofstream archivoSalida(nombreFicheroSalida, ios::binary);
    if (!archivoSalida.is_open()) 
    {
        cerr << "No se pudo crear el archivo de salida " << nombreFicheroSalida << endl;
        return 1;
    }
    string linea;
    while (getline(archivoEntrada, linea)) 
    {
        stringstream ss(linea);
        double numero;
        while (ss >> numero) 
        {
            archivoSalida.write(reinterpret_cast<const char*>(&numero), sizeof(double));
        }
    } 
    // cerrar los archivos de entrada y salida
    archivoEntrada.close();
    archivoSalida.close();
    cout << "Se han grabado los numeros en formato binario en el archivo " << nombreFicheroSalida << endl;
    return 0;
}