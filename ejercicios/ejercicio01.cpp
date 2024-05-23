#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    system("cls");
    ofstream salida;
    salida.open("hola.txt");
    salida << "hola mundo";
    salida.close();   
    return 0;
}
