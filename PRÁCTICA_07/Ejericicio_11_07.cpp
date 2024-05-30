// Materia: Programación I, Paralelo 1
// Autor: Neider Quispe Paye
// Fecha creación: 26/05/2024
// Fecha modificación: 28/05/2024
// Número de ejercicio: 11
/* Problema planteado: 11 Amplíe el programa anterior que procesa clientes de una agencia matrimonial para que tome
los datos de todos los candidatos a estudiar del fichero PERSONAS.DAT del ejercicio anterior,
lea el nombre del cliente por teclado y finalmente genere como resultado un listado por
pantalla con los nombres de los candidatos aceptados y un fichero llamado ACEPTADOS.BIN
con toda la información correspondiente a los candidatos aceptados.
Una persona del fichero PERSONAS.DAT se considerará aceptable como candidato si tiene
diferente sexo y que haya nacido en el mes y año (El programa debe ser capaz de trabajar con
cualquier número de personas en el fichero PERSONAS.DAT).*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
void leerPersona();
void crearArchivoPersonas();
void procesarClientes();
int main() 
{
    int opcion;
    do {
        cout << "Menu:\n";
        cout << "1. Crear archivo de personas\n";
        cout << "2. Procesar clientes\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 
        switch (opcion) 
        {
            case 1:
                crearArchivoPersonas();
                break;
            case 2:
                procesarClientes();
                break;
            case 3:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida, intente de nuevo.\n";
                break;
        }
    } 
    while (opcion != 3);

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
    if (input == " ") {
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
    cout << "Ingrese la fecha de nacimiento (dd/mm/yyyy): ";
    getline(cin, input);
    strncpy(p.fechaNacimiento, input.c_str(), sizeof(p.fechaNacimiento) - 1);
    p.fechaNacimiento[sizeof(p.fechaNacimiento) - 1] = '\0';
}
void crearArchivoPersonas() 
{
    ofstream archivo("PERSONAS.BIN", ios::binary);
    if (!archivo.is_open()) 
    {
        cerr << "No se pudo crear el archivo PERSONAS.BIN" << endl;
        return;
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
}
void procesarClientes() 
{
    ifstream archivoPersonas("PERSONAS.BIN", ios::binary);
    if (!archivoPersonas.is_open()) 
    {
        cerr << "No se pudo abrir el archivo PERSONAS.BIN" << endl;
        return;
    }
    vector<Persona> personas;
    Persona p;
    while (archivoPersonas.read(reinterpret_cast<char*>(&p), sizeof(p))) 
    {
        personas.push_back(p);
    }
    archivoPersonas.close();
    string nombreCliente;
    char sexoCliente;
    string fechaNacimientoCliente;
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nombreCliente);
    cout << "Ingrese el sexo del cliente (M/F): ";
    cin >> sexoCliente;
    // Ignorar el salto 
    cin.ignore(); 
    cout << "Ingrese la fecha de nacimiento del cliente (dd/mm/yyyy): ";
    getline(cin, fechaNacimientoCliente);
    ofstream archivoAceptados("ACEPTADOS.BIN", ios::binary);
    if (!archivoAceptados.is_open()) 
    {
        cerr << "No se pudo crear el archivo ACEPTADOS.BIN" << endl;
        return;
    }
    cout << "Candidatos aceptados:\n";
    for (const auto& persona : personas) 
    {
        if (persona.sexo != sexoCliente &&
            strncmp(persona.fechaNacimiento + 3, fechaNacimientoCliente.c_str() + 3, 7) == 0) {
            cout << persona.nombre << endl;
            archivoAceptados.write(reinterpret_cast<const char*>(&persona), sizeof(persona));
        }
    }
    archivoAceptados.close();
    cout << "Informacion guardada en ACEPTADOS.BIN" << endl;
}