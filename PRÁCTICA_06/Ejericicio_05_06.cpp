// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 15/05/2024
// Fecha modificación: 18/05/2024
// Número de ejercicio: 5
// Problema planteado: Realizar un algoritmo recursivo para comparar si dos vectores son iguales

#include <iostream>
#include <vector>

using namespace std;
bool sonIguales(const vector<int>& vec1, const vector<int>& vec2, int index, int size);
int main() 
{
    vector<int> vector1 = {1, 2, 3, 4, 5};
    vector<int> vector2 = {1, 2, 3, 4, 5}; 
    // Comparamos los tamaños de los vectores
    if (vector1.size() != vector2.size()) 
    {
        cout << "Los vectores no son iguales." << endl;
        return 0;
    }
    if (sonIguales(vector1, vector2, 0, vector1.size())) 
    {
        cout << "Los vectores son iguales." << endl;
    } else 
    {
        cout << "Los vectores no son iguales." << endl;
    }
    return 0;
}
// Funcion para comparar dos vectores
bool sonIguales(const vector<int>& vec1, const vector<int>& vec2, int index, int size) 
{
    if (index == size) 
    {
        return true;
    }
    if (vec1[index] != vec2[index]) 
    {
        return false;
    }
    return sonIguales(vec1, vec2, index + 1, size);
}
