// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 27/05/2024
// Número de ejercicio: 5
// Problema planteado: 5 Copiar un fichero de texto en otro.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Limpia la pantalla 
    system("cls");

    // Nombres de los archivos
    string archivoOrigen = "hola.txt";
    string archivoDestino = "copia_hola.txt";

    ifstream entrada(archivoOrigen);
    if (!entrada.is_open()) {
        cout << "Error al abrir el archivo de origen: " << archivoOrigen << endl;
        return 1;
    }
    ofstream salida(archivoDestino);
    if (!salida.is_open()) 
    {
        cout << "Error al abrir el archivo de destino: " << archivoDestino << endl;
        entrada.close();
        return 1;
    }
    string texto;
    while (getline(entrada, texto)) {
        salida << texto << endl;
    }
    entrada.close();
    salida.close();

    cout << "Archivo copiado con exito." << endl;
    return 0;
}
