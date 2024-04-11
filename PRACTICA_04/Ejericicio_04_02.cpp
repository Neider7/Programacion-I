// Materia: Programaci�n I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creaci�n: 08/04/2024
// Fecha modificaci�n: 10/04/2024
// N�mero de ejercicio: 02_01
/* Ingresar el tama�o de un vector de m�s de 5 elementos y llenar con n�mero aleatorios entre 1 y 1000, desplegar el vector original y luego ordenarlo con los siguientes m�todos.
		1.- Ordenar por selecci�n.
		2.- Ordenar por inserci�n.
		3.- Ordenar por el m�todo burbuja.
		4.- Ordenar por Shell.
		5.- Ordenar por Quicksort.	*/

#include <iostream>

#include <vector>

#include <cstdlib>

using namespace std;

void swap(int &a, int &b);

void Ordenar_por_seleccion(vector<int> &ordenar);

int main() 
{
    int cantidad_vector;
    int inicio = 1, final = 1000;
    vector<int> vector_1;
    
    cout << "Ingrese el tamanio del vector: ";
    cin >> cantidad_vector;

    // Generar numeros aleatorios y almacenarlos en el vector
    for (int i = 0; i < cantidad_vector; i++) 
	{
        vector_1.push_back(rand() % (final - inicio + 1) + inicio);
    }

    cout << "Vector antes de ordenar:" << endl;
    for (int i = 0; i < cantidad_vector; i++) 
	{
        cout << vector_1[i] << "\t"; 
    } 
    cout << endl;

    Ordenar_por_seleccion(vector_1);

    cout << "Vector ordenado:" << endl;
    for (int i = 0; i < cantidad_vector; i++) 
	{
        cout << vector_1[i] << "\t"; 
    } 
    cout << endl;

    return 0;
}
// intercambiar dos elementos en un vector
void swap(int &a, int &b) 
{
    int aux = a;
    a = b;
    b = aux;
}

// Metodo de ordenacion por seleccion
void Ordenar_por_seleccion(vector<int> &ordenar) 
{
    int n = ordenar.size();
    for (int i = 0; i < n - 1; i++) 
	{
        int primer_valor = i;
        for (int j = i + 1; j < n; j++) 
		{
            if (ordenar[j] < ordenar[primer_valor]) 
			{
                primer_valor = j;
            }
        }
        if (primer_valor != i) 
		{
            swap(ordenar[i], ordenar[primer_valor]);
        }
    }
}


