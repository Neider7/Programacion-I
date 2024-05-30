// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 30/05/2024
// Número de ejercicio: 14
/* Problema planteado: 14 Escriba un programa que tome como entrada el fichero del ejercicio 4 y una condición sobre el
campo Precio. La condición podrá ser:
Precio mayor o igual a 100 o cualquier otro dato ingresado por teclado.
Este programa debe generar como salida un fichero llamado "salida.dat" que contenga todos
aquellos artículos para los que se cumple la condición de entrada.
Mostrar el archivo de salida “salida.dat” */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
struct Articulo 
{
    int codigo;
    char nombre[51];
    int existencias;
    double precio;
};
void leerFichero(const string& nombreFichero, vector<Articulo>& articulos);
void escribirFichero(const string& nombreFichero, const vector<Articulo>& articulos);
void mostrarFichero(const string& nombreFichero);
int main() 
{
    vector<Articulo> articulos, articulosFiltrados;
    double precioCondicion;
    // Leer los datos de entrada
    leerFichero("ARTICULOS.BIN", articulos);
    // condicion sobre el precio
    cout << "Ingrese la condicion sobre el precio (por ejemplo, mayor o igual a 100): ";
    cin >> precioCondicion;
    for (const auto& articulo : articulos) 
    {
        if (articulo.precio >= precioCondicion) 
        {
            articulosFiltrados.push_back(articulo);
        }
    }
    escribirFichero("salida.dat", articulosFiltrados);
    cout << "Contenido del fichero salida.dat:\n";
    mostrarFichero("salida.dat");
    return 0;
}
void leerFichero(const string& nombreFichero, vector<Articulo>& articulos) 
{
    ifstream archivo(nombreFichero, ios::binary);
    if (!archivo.is_open()) 
    {
        cerr << "No se pudo abrir el archivo " << nombreFichero << endl;
        return;
    }
    Articulo articulo;
    while (archivo.read(reinterpret_cast<char*>(&articulo), sizeof(articulo))) 
    {
        articulos.push_back(articulo);
    }
    archivo.close();
}
void escribirFichero(const string& nombreFichero, const vector<Articulo>& articulos) 
{
    ofstream archivo(nombreFichero, ios::binary);
    if (!archivo.is_open()) 
    {
        cerr << "No se pudo crear el archivo " << nombreFichero << endl;
        return;
    }
    for (const auto& articulo : articulos) 
    {
        archivo.write(reinterpret_cast<const char*>(&articulo), sizeof(articulo));
    }
    archivo.close();
}
void mostrarFichero(const string& nombreFichero) 
{
    ifstream archivo(nombreFichero, ios::binary);
    if (!archivo.is_open()) 
    {
        cerr << "No se pudo abrir el archivo " << nombreFichero << endl;
        return;
    }
    Articulo articulo;
    while (archivo.read(reinterpret_cast<char*>(&articulo), sizeof(articulo))) 
    {
        cout << "Codigo: " << articulo.codigo << "\n";
        cout << "Nombre: " << articulo.nombre << "\n";
        cout << "Existencias: " << articulo.existencias << "\n";
        cout << "Precio: " << articulo.precio << "\n";
        cout << "--------------------------\n";
    }
    archivo.close();
}