// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 30/05/2024
// Número de ejercicio: 15
/* Problema planteado: 15 Escriba un programa que tenga como entrada un fichero que contenga un texto y dé como
resultado una estadística del número de palabras.*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Contar las palabras en un texto
int contarPalabras(const string& texto) 
{
    stringstream ss(texto);
    string palabra;
    int contador = 0;
    while (ss >> palabra) 
    {
        contador++;
    }
    return contador;
}

int main() 
{
    string nombreFichero;
    cout << "Ingrese el nombre del fichero de texto: ";
    cin >> nombreFichero;
    ifstream archivo(nombreFichero);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreFichero << endl;
        return 1;
    }
    stringstream buffer;
    buffer << archivo.rdbuf(); 
    string texto = buffer.str();
    int numeroDePalabras = contarPalabras(texto);
    cout << "Numero de palabras en el fichero: " << numeroDePalabras << endl;
    archivo.close();
    return 0;
}
