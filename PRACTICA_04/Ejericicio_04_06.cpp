// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 08/04/2024
// Fecha modificación: 10/04/2024
// Número de ejercicio: 02_05
/* Ingresar el tamaño de un vector de más de 5 elementos y llenar con número aleatorios entre 1 y 1000, desplegar el vector original y luego ordenarlo con los siguientes métodos.
		1.- Ordenar por selección.
		2.- Ordenar por inserción.
		3.- Ordenar por el método burbuja.
		4.- Ordenar por Shell.
		5.- Ordenar por Quicksort.	*/
		
#include <iostream>

#include <vector>

#include <cstdlib>

using namespace std;

void metodo_quickSort(vector<int> &ordenar, int indice_bajo, int indice_alto);

int arreglo(vector<int> &ordenar, int indice_bajo, int indice_alto);

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

    // Llamar a la funcion de Quicksort 
    metodo_quickSort(vector_1, 0, cantidad_vector - 1);

    cout << "Vector ordenado:" << endl;
    for (int i = 0; i < cantidad_vector; i++) 
	{
        cout << vector_1[i] << "\t"; 
    } 
    cout << endl;

    return 0;
}

int arreglo(vector<int> &ordenar, int indice_bajo, int indice_alto) 
{
    int pivote = ordenar[indice_alto];
    int i = (indice_bajo - 1); 
    for (int j = indice_bajo; j <= indice_alto - 1; j++) 
	{
        // Si el elemento actual es menor o igual al pivote
        if (ordenar[j] <= pivote) 
		{
            i++;    
            
            int temporal = ordenar[i];
            ordenar[i] = ordenar[j];
            ordenar[j] = temporal;
        }
    }

    int temporal = ordenar[i + 1];
    ordenar[i + 1] = ordenar[indice_alto];
    ordenar[indice_alto] = temporal;
    return (i + 1);
}

// Funcion Quicksort
void metodo_quickSort(vector<int> &ordenar, int indice_bajo, int indice_alto) 
{
    if (indice_bajo < indice_alto) 
	{
        int pivote_arreglo = arreglo(ordenar, indice_bajo, indice_alto);

        metodo_quickSort(ordenar, indice_bajo, pivote_arreglo - 1);
        metodo_quickSort(ordenar, pivote_arreglo + 1, indice_alto);
    }
}

