#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    system("cls");
    int valor;
    cout <<"numero a mostra ASCII >= 32 y <= 255"<<endl;
    cin >> valor;
    ofstream salida;
    salida.open("caracteres_ASCII.txt");
    for (int i = 32; i <= valor; i++)
    {
        salida <<" caracter:  "<<char(i)<<endl;
    } 
    salida.close(); 
    return 0;
}