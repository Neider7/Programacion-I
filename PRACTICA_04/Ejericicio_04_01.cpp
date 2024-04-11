// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 08/04/2024
// Fecha modificación: 10/04/2024
// Número de ejercicio: 1
// Problema planteado: Realizar el algoritmo de auclides

#include <iostream>

#include <vector>

using namespace std;

void euclides(int valor_a, int valor_b, int &mcd);

int main() 
{
    int numero_1, numero_2;
    
    cout << "Ingrese el primer numero entero: ";
    cin >> numero_1;

    cout << "Ingrese el segundo numero entero: ";
    cin >> numero_2;

    int mcd;
    euclides(numero_1, numero_2, mcd);
    
    cout << "El MCD de " << numero_1 << " y " << numero_2 << " es: " << mcd << endl;

    return 0;
}
// Función para calcular el MCD usando el algoritmo de Euclides
void euclides(int valor_a, int valor_b, int &mcd) 
{
    while (valor_b != 0) 
	{
        int aux = valor_b;
        valor_b = valor_a % valor_b;
        valor_a = aux;
    }
    mcd = valor_a;
}
