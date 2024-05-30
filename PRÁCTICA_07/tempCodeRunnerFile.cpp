// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 27/05/2024
// Número de ejercicio: 8
// Problema planteado: 8 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void agregarEstudiante();
void mostrarEstudiantes();

int main() 
{
    int opcion;

    do 
    {
        cout << "Menu:\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea restante en el buffer
        switch (opcion) 
        {
            case 1:
                agregarEstudiante();
                break;
            case 2:
                mostrarEstudiantes();
                break;
            case 3:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 3);

    return 0;
}

void agregarEstudiante() 
{
    ofstream archivo("estudiantes.txt", ios::app);
    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }
    string nombre, apellidos, programa;
    double nota;
    // Pedir datos al usuario
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);
    cout << "Ingrese los apellidos del estudiante: ";
    getline(cin, apellidos);
    cout << "Ingrese el programa académico que estudia el estudiante: ";
    getline(cin, programa);
    cout << "Ingrese la nota del curso del estudiante: ";
    cin >> nota;
    cin.ignore();
    // Escribir los datos en el archivo
    archivo << nombre << ";" << apellidos << ";" << programa << ";" << nota << endl;
    archivo.close();
    cout << "Datos guardados correctamente en el archivo 'estudiantes.txt'" << endl;
}

void mostrarEstudiantes() 
{
    ifstream archivo("estudiantes.txt");
    if (!archivo.is_open()) 
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }
    string linea;
    int contador = 0;
    cout << "Listado de estudiantes : ";
    while (getline(archivo, linea)) 
    {
        cout << linea << endl;
        contador++;
    }
    archivo.close();
    cout << "Número total de registros: " << contador << endl;
}
