// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 15/05/2024
// Fecha modificación: 18/05/2024
// Número de ejercicio: 2
// Problema planteado: Realizar un algoritmo para generar la secuencia: 1, 1, 2, 4, 8, 16, 23, 28, 38,
// 49,..., para n términos.

#include <iostream>
#include <vector>

using namespace std;

int calcularTermino(int n, vector<int>& memoria);
void generarSecuencia(int n);

int main() 
{
    int n;   
    cout << "Introduce el numero de la secuencia: ";
    cin >> n;  
    generarSecuencia(n);  
    return 0;
}
void generarSecuencia(int n) 
{
    vector<int> secuencia(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        secuencia[i] = calcularTermino(i, secuencia);
    }
    cout << "La secuencia es: ";
    for (int i = 1; i <= n; ++i) {
        cout << secuencia[i] << " ";
    }
    cout << endl;
}
// Funcion recursiva de la secuencia
int calcularTermino(int n, vector<int>& memoria) 
{
    if (n == 1 || n == 2) 
    {
        return 1;
    } 
    else 
    if (n == 3) 
    {
        return 2;
    } 
    else 
    if (n == 4) 
    {
        return 4;
    } 
    else 
    if (n == 5) 
    {
        return 8;
    } 
    else 
    if (n == 6) 
    {
        return 16;
    } 
    // Verificar si ya hemos calculado el valor
    if (memoria[n] != -1) {
        return memoria[n];
    }
    // almacenarlo memoria
    memoria[n] = calcularTermino(n - 1, memoria) + calcularTermino(n - 3, memoria);
    return memoria[n];
}