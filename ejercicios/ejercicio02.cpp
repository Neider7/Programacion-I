#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    system("cls");
    ifstream entrada;
    entrada.open("hola.txt");
    string texto;  
    getline(entrada,texto);
    cout << texto << endl;
    entrada.close();
    return 0;
}
