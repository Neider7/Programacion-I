// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 28/05/2024
// Número de ejercicio: 8
/* Problema planteado: 8  Permitir obtener un listado en pantalla, de los datos que contiene el archivo creado en el punto
anterior. Al terminar el listado se debe informar el número de registros contenidos en el
archivo*/ 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void agregarEstudiante();
void mostrarEstudiantes();

int main() 
{
    int opcion;
    do {
        cout << "Menu:\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        // Ignorar el salto de linea
        cin.ignore(); 
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
                cout << "Opcion no valida.\n";
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
    // datos al usuario
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);
    cout << "Ingrese los apellidos del estudiante: ";
    getline(cin, apellidos);
    cout << "Ingrese el programa académico que estudia el estudiante: ";
    getline(cin, programa); 
    cout << "Ingrese la nota del curso del estudiante: ";
    cin >> nota;
    cin.ignore();
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
    cout << "Listado de estudiantes:\n";
    while (getline(archivo, linea)) 
    {
        cout << linea << endl;
        contador++;
    }
    archivo.close();
    cout << "Numero total de registros: " << contador << endl;
}
