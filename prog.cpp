#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 

    int idade = 2023 - atoi(argv[2]);

    if (argc == 3)
    {
        cout << "seu nome: " << argv[1] << endl;
        cout << "Ano de nascimento: " << argv[2] << endl;
        cout << "Sua idade: " << idade << endl;
        
    }else if (argc == 1)
    {
        cout << "Argumentos insuficientes, insira o nome e o ano do seu nascimento. " << endl;
    }else{

        cout << "Argumentos Estrapolados, insira o nome e o ano do seu nascimento. " << endl;

    }
    

    return 0;
}