#include <iostream>

using namespace std;

int main(void)
{
    system("clear");

    char letra;

    cout << "Digite uma letra: ";

    cin >> letra;

    // Pra modificar o comportamento do cout para imprimir um objeto de tipo char como número basta convertela para o tipo inteiro

    cout << "'" << letra << "' e igual a " << int(letra) << " na tabela ASCII em inteiro." << endl;
    cout << "'" << letra << "' e igual a " << hex << int(letra) << " na tabela ASCII em Hexadecimal." << endl;
    cout << "'" << letra << "' e igual a " << oct << int(letra) << " na tabela ASCII em octadecimal./n" << endl;


    return 0;
}
