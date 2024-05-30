// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 28/05/2024
// Número de ejercicio: 10
/* Problema planteado: 10 Escriba un programa que cree un fichero binario llamado "PERSONAS.BIN" en el que se guarde
la información de un número indeterminado de personas.
La información que se guardará por cada persona será:
• Nombre: De 1 a 30 caracteres. WILLY TENORIO
• Edad numérico (>= 1 y <=100) 40
• Sexo CHAR (M/F). M
• FechaNacimiento CHAR(10) (formato dd/mm/yyyy) 01/01/1980
La información correspondiente a cada persona se leerá del teclado.
El proceso finalizará cuando se teclee un campo "Nombre" que esté solamente con el carácter
de espacio. */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void leerPersona(Persona &p);
int main() 
{
    ofstream archivo("PERSONAS.BIN", ios::binary);
    if (!archivo.is_open()) 
    {
        cerr << "No se pudo crear el archivo PERSONAS.BIN" << endl;
        return 1;
    }
    Persona persona;
    while (true) 
    {
        leerPersona(persona);
        if (persona.nombre[0] == ' ' && persona.nombre[1] == '\0') {
            break;
        }
        archivo.write(reinterpret_cast<const char*>(&persona), sizeof(persona));
    }
    archivo.close();
    cout << "Informacion guardada en PERSONAS.BIN" << endl;
    return 0;
}
struct Persona 
{
    char nombre[31]; 
    int edad;
    char sexo;
    char fechaNacimiento[11];
};

void leerPersona(Persona &p) 
{
    string input;
    cout << "Ingrese el nombre (de 1 a 30 caracteres, solo espacio para terminar): ";
    getline(cin, input);
    if (input == " ") 
    {
        p.nombre[0] = ' ';
        p.nombre[1] = '\0';
        return;
    }
    strncpy(p.nombre, input.c_str(), sizeof(p.nombre) - 1);
    p.nombre[sizeof(p.nombre) - 1] = '\0';
    cout << "Ingrese la edad (1-100): ";
    cin >> p.edad;
    cin.ignore(); 
    cout << "Ingrese el sexo (M/F): ";
    cin >> p.sexo;
    cin.ignore();
    cout << "Ingrese la fecha de nacimiento (formato dd/mm/yyyy): ";
    getline(cin, input);
    strncpy(p.fechaNacimiento, input.c_str(), sizeof(p.fechaNacimiento) - 1);
    p.fechaNacimiento[sizeof(p.fechaNacimiento) - 1] = '\0';
}