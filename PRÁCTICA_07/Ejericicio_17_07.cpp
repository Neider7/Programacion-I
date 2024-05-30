// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 30/05/2024
// Número de ejercicio: 17
/* Problema planteado: 17 Dado una tabla grabada en un fichero en formato binario <nombre>.BIN hallar la suma
horizontal y vertical y grabar la tabla y los resultados en otro fichero de texto o binario según se
introduzca por pantalla.
El resultado en texto sería el siguiente:
Ej:
1.23 3.45 12.5 17,18
4.8 3.9 0.83 9,53
6,03 7,35 13,33 26,71 */

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Prototipos de funciones
bool leerTablaBinaria(const string& nombreFichero, vector<vector<double>>& tabla);
void calcularSumas(const vector<vector<double>>& tabla, vector<double>& sumaHorizontal, vector<double>& sumaVertical);
void guardarTablaEnTexto(const string& nombreFichero, const vector<vector<double>>& tabla, const vector<double>& sumaHorizontal, const vector<double>& sumaVertical);

int main() 
{
    string nombreFicheroEntrada, nombreFicheroSalida;
    char opcion;
    cout << "Ingrese el nombre del fichero de entrada (.BIN): ";
    cin >> nombreFicheroEntrada;
    vector<vector<double>> tabla;
    if (!leerTablaBinaria(nombreFicheroEntrada, tabla)) 
    {
        return 1;
    }
    vector<double> sumaHorizontal, sumaVertical;
    calcularSumas(tabla, sumaHorizontal, sumaVertical);
    cout << "Ingrese 't' para guardar en texto o 'b' para guardar en binario: ";
    cin >> opcion;
    cout << "Ingrese el nombre del fichero de salida: ";
    cin >> nombreFicheroSalida;
    if (opcion == 't') 
    {
        nombreFicheroSalida += ".txt";
    } else if (opcion == 'b') 
    {
        nombreFicheroSalida += ".BIN";
    } else {
        cerr << "Opcion no valida." << endl;
        return 1;
    }
    // Guardar la tabla y los resultados en el archivo de salida
    if (opcion == 't') 
    {
        guardarTablaEnTexto(nombreFicheroSalida, tabla, sumaHorizontal, sumaVertical);
    } else if (opcion == 'b') 
    {
        ofstream archivoSalidaBinario(nombreFicheroSalida, ios::binary);
        if (!archivoSalidaBinario.is_open()) 
        {
            cerr << "No se pudo crear el archivo " << nombreFicheroSalida << endl;
            return 1;
        }
        int filas = tabla.size();
        int columnas = tabla[0].size();
        archivoSalidaBinario.write(reinterpret_cast<const char*>(&filas), sizeof(int));
        archivoSalidaBinario.write(reinterpret_cast<const char*>(&columnas), sizeof(int));
        for (int i = 0; i < filas; ++i) 
        {
            for (int j = 0; j < columnas; ++j) 
            {
                archivoSalidaBinario.write(reinterpret_cast<const char*>(&tabla[i][j]), sizeof(double));
            }
        }
        archivoSalidaBinario.close();
    }
    cout << "Se ha guardado la tabla y los resultados en el archivo " << nombreFicheroSalida << endl;
    return 0;
}

bool leerTablaBinaria(const string& nombreFichero, vector<vector<double>>& tabla) 
{
    ifstream archivo(nombreFichero, ios::binary);
    if (!archivo.is_open()) 
    {
        cerr << "No se pudo abrir el archivo " << nombreFichero << endl;
        return false;
    }
    int filas, columnas;
    archivo.read(reinterpret_cast<char*>(&filas), sizeof(int));
    archivo.read(reinterpret_cast<char*>(&columnas), sizeof(int));
    tabla.resize(filas, vector<double>(columnas));
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            archivo.read(reinterpret_cast<char*>(&tabla[i][j]), sizeof(double));
        }
    }
    archivo.close();
    return true;
}
void calcularSumas(const vector<vector<double>>& tabla, vector<double>& sumaHorizontal, vector<double>& sumaVertical) 
{
    int filas = tabla.size();
    int columnas = tabla[0].size();
    sumaHorizontal.resize(filas, 0);
    sumaVertical.resize(columnas, 0);
    if (filas == 0 || columnas == 0) 
    {
        cerr << "La tabla está vacía." << endl;
        return;
    }
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            sumaHorizontal[i] += tabla[i][j];
            sumaVertical[j] += tabla[i][j];
        }
    }
}
void guardarTablaEnTexto(const string& nombreFichero, const vector<vector<double>>& tabla, const vector<double>& sumaHorizontal, const vector<double>& sumaVertical) 
{
    ofstream archivo(nombreFichero);
    if (!archivo.is_open()) 
    {
        cerr << "No se pudo crear el archivo " << nombreFichero << endl;
        return;
    }
    int filas = tabla.size();
    int columnas = tabla[0].size();
    // Guardar la tabla
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            archivo << fixed << setprecision(2) << tabla[i][j] << " ";
        }
        archivo << fixed << setprecision(2) << sumaHorizontal[i] << endl;
    }
    // Guardar las sumas verticales
    for (double suma : sumaVertical) 
    {
        archivo << fixed << setprecision(2) << suma << " ";
    }
    archivo << endl;
    archivo.close();
}