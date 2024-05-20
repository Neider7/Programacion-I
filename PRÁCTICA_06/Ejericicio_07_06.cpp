// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 19/05/2024
// Fecha modificación: 19/05/2024
// Número de ejercicio: 7
// Problema planteado: Realizar un algoritmo recursivo para el siguiente problema: un granjero ha
// comprado una pareja de conejos para criarlos y luego venderlos. Si la pareja de
// conejos produce una nueva pareja cada mes y la nueva pareja tarda un mes
// más en ser también productiva, ¿cuántos pares de conejos podrá poner a la
// venta el granjero al cabo de un año?

#include <iostream>

using namespace std;
int contarConejos(int mes);

int main() 
{
    int meses = 12; 
    int parejas = contarConejos(meses);
    
    cout << "El granjero podra poner a la venta " << parejas << " pares de conejos al cabo de un anio." << endl;

    return 0;
}
// Función recursiva para calcular el numero de parejas de conejos en un mes dado
int contarConejos(int mes) 
{
    if (mes == 0 || mes == 1) 
    {
        return 1;
    }
    // calcular el numero de parejas de conejos en el mes actual
    return contarConejos(mes - 1) + contarConejos(mes - 2);
}