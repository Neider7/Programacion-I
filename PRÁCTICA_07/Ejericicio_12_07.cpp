// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 29/05/2024
// Número de ejercicio: 12
/* Problema planteado: 12 Codifique un programa que cree un fichero para contener los datos relativos a los artículos de
un almacén.
Para cada artículo habrá de guardar la siguiente información:
• Código del artículo (Numérico)
• Nombre del artículo (Cadena de caracteres)
• Existencias actuales (Numérico)
• Precio (Numérico decimal).
Se deberán pedir datos de cada artículo por teclado hasta que como código se teclee el código
0.
El fichero se habrá de crear ordenado por el código del artículo.*/

#include <iostream>
#include <fstream>
#include <string>
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
// Comparador para ordenar
bool compararPorCodigo(const Articulo &a, const Articulo &b) 
{
    return a.codigo < b.codigo;
}
int main() 
{
    vector<Articulo> articulos;
    Articulo articulo;
    string input;
    while (true) 
    {
        cout << "Ingrese el codigo del articulo (0 para terminar): ";
        cin >> articulo.codigo;
        cin.ignore(); 
        if (articulo.codigo == 0) 
        {
            break;
        }
        cout << "Ingrese el nombre del articulo: ";
        cin.getline(articulo.nombre, 51);
        cout << "Ingrese las existencias actuales: ";
        cin >> articulo.existencias;
        cin.ignore(); 
        cout << "Ingrese el precio del articulo: ";
        cin >> articulo.precio;
        cin.ignore(); 

        articulos.push_back(articulo);
    }
    // Ordenar los articulos
    sort(articulos.begin(), articulos.end(), compararPorCodigo);
    // Crear el archivo binario y escribir
    ofstream archivo("ARTICULOS.BIN", ios::binary);
    if (!archivo.is_open()) 
    {
        cerr << "No se pudo crear el archivo ARTICULOS.BIN" << endl;
        return 1;
    }
    for (const auto &art : articulos) 
    {
        archivo.write(reinterpret_cast<const char*>(&art), sizeof(art));
    }
    archivo.close();
    cout << "Informacion guardada en ARTICULOS.BIN" << endl;
    return 0;
}