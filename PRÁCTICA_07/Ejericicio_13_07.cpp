// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 30/05/2024
// Número de ejercicio: 13
/* Problema planteado: 13 Escriba un programa que dados dos ficheros generados por el programa anterior y ordenados
genere un tercer fichero que sea el resultado de mezclar de formar ordenada los dos primeros. */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
struct Articulo 
{
    int codigo;
    char nombre[51];
    int existencias;
    double precio;
};
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
vector<Articulo> mezclarOrdenadamente(const vector<Articulo>& articulos1, const vector<Articulo>& articulos2) 
{
    vector<Articulo> mezclados;
    size_t i = 0, j = 0;
    while (i < articulos1.size() && j < articulos2.size()) 
    {
        if (articulos1[i].codigo < articulos2[j].codigo) 
        {
            mezclados.push_back(articulos1[i]);
            i++;
        } else 
        {
            mezclados.push_back(articulos2[j]);
            j++;
        }
    }
    // Agregar los elementos restantes
    while (i < articulos1.size()) 
    {
        mezclados.push_back(articulos1[i]);
        i++;
    }
    while (j < articulos2.size()) 
    {
        mezclados.push_back(articulos2[j]);
        j++;
    }

    return mezclados;
}
int main() 
{
    vector<Articulo> articulos1, articulos2, articulosMezclados;
    leerFichero("ARTICULOS1.BIN", articulos1);
    leerFichero("ARTICULOS2.BIN", articulos2);
    articulosMezclados = mezclarOrdenadamente(articulos1, articulos2);
    escribirFichero("ARTICULOS_MEZCLADOS.BIN", articulosMezclados);
    cout << "Los archivos se han mezclado y guardado en ARTICULOS_MEZCLADOS.BIN" << endl;
    return 0;
}