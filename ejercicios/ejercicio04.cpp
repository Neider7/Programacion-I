#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    system("cls");
    ifstream caracteres;
    caracteres.open("caracteres_ASCII.txt");
    string texto;
    while (!caracteres.eof())
    {
        getline(caracteres,texto);
        cout <<texto<<endl;
    }
    caracteres.close();

    return 0;
}