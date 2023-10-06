#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;



void pause();
void limpaTela();

int menu();
int main(){
    
    return 0;
}

void pause()
{
    cin.ignore();
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void limpaTela()
{
    cin.clear();

    // Verifica se a variável de ambiente WINDIR está definida (ambiente Windows)
    const char *windir = getenv("WINDIR");

    if (windir != nullptr && strlen(windir) > 0)
    {
        // Se estiver definida, estamos no Windows, então use "cls"
        system("cls");
    }
    else
    {
        // Caso contrário, estamos em um ambiente Unix/Linux, use "clear"
        system("clear");
    }
}

int menu(){
    int opc;

    cout << "########## MENU ##########" << endl;
    cout << "1.Gerar um Retangulo" << endl;
    cout << "2.Calcular Area do Retangulo" << endl;
    cout << "3.Gerar um Circulo" << endl;
    cout << "4.Calcular Area do Circulo" << endl;
    cout << "0.Sair" << endl;
    cout << "Informe sua Opcao: ";
    cin >> opc;

    return opc;
}

