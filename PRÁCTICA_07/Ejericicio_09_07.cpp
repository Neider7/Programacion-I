// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 28/05/2024
// Número de ejercicio: 9
/* Problema planteado: 9 Escribir un programa con la opción de encriptar y de desencriptar un fichero de texto.
La encriptación consiste en que dado un fichero de texto de entrada genere otro fichero de
salida de extensión <nombre>.COD donde el texto estará codificado (encriptado).
Esta codificación consiste en reemplazar cada carácter por el tercero siguiente según la tabla
ASCII.
La opción de desencriptado consiste en leer un fichero <nombre>.COD y recuperar la
información original.*/  

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encriptarFichero(const string& nombreFichero);
void desencriptarFichero(const string& nombreFicheroCOD);

int main() 
{
    int opcion;
    string nombreFichero;
    do {
        cout << "Menu:\n";
        cout << "1. Encriptar fichero\n";
        cout << "2. Desencriptar fichero\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) 
        {
            case 1:
                cout << "Ingrese el nombre del fichero a encriptar (con extension): ";
                getline(cin, nombreFichero);
                encriptarFichero(nombreFichero);
                break;
            case 2:
                cout << "Ingrese el nombre del fichero a desencriptar (con extension .COD): ";
                getline(cin, nombreFichero);
                desencriptarFichero(nombreFichero);
                break;
            case 3:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no valida.\n";
                break;
        }
    } 
    while (opcion != 3);
    return 0;
}

void encriptarFichero(const string& nombreFichero) 
{
    ifstream archivoEntrada(nombreFichero);
    if (!archivoEntrada.is_open()) 
    {
        cerr << "No se pudo abrir el fichero de entrada: " << nombreFichero << endl;
        return;
    }
    string nombreFicheroSalida = nombreFichero + ".COD";
    ofstream archivoSalida(nombreFicheroSalida);
    if (!archivoSalida.is_open()) 
    {
        cerr << "No se pudo crear el fichero de salida: " << nombreFicheroSalida << endl;
        return;
    }
    char c;
    while (archivoEntrada.get(c)) 
    {
        archivoSalida.put(c + 3);
    }
    archivoEntrada.close();
    archivoSalida.close();
    cout << "Fichero encriptado guardado como: " << nombreFicheroSalida << endl;
}
void desencriptarFichero(const string& nombreFicheroCOD) 
{
    ifstream archivoEntrada(nombreFicheroCOD);
    if (!archivoEntrada.is_open()) 
    {
        cerr << "No se pudo abrir el fichero de entrada: " << nombreFicheroCOD << endl;
        return;
    }
    string nombreFicheroSalida = nombreFicheroCOD.substr(0, nombreFicheroCOD.size() - 4);
    ofstream archivoSalida(nombreFicheroSalida);
    if (!archivoSalida.is_open()) {
        cerr << "No se pudo crear el fichero de salida: " << nombreFicheroSalida << endl;
        return;
    }
    char c;
    while (archivoEntrada.get(c)) 
    {
        archivoSalida.put(c - 3); 
    }
    archivoEntrada.close();
    archivoSalida.close();
    cout << "Fichero desencriptado guardado como: " << nombreFicheroSalida << endl;
}
