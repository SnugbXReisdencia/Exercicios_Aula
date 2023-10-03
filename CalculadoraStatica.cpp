# include <iostream>
# include <limits>
# include <cstring>
# include <cmath>

using namespace std;

class Calculadora{
    public:
        static int soma(int, int);
        static int subtracao(int, int);
        static int multiplicacao(int, int);
        static int divisao(int, int);
        static int potencia(int, int);

};

int Calculadora::soma(int a, int b){
    return a + b;
}

int Calculadora::subtracao(int a, int b){
    return a - b;
}

int Calculadora::multiplicacao(int a, int b){
    return a * b;
}

int Calculadora::divisao(int a, int b){
    if (b == 0){
        cout << "Divisão por 0 não pode" << endl;
        return 0;
    }
    return a / b;
}

int Calculadora::potencia(int a, int b){
    return pow(a, b);
}

int Menu(){
    int opcao;
    cout << "1 - Soma" << endl;
    cout << "2 - Subtracao" << endl;
    cout << "3 - Multiplicacao" << endl;
    cout << "4 - Divisao" << endl;
    cout << "5 - Potencia" << endl;
    cout << "6 - Sair" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    return opcao;
}

void pause();
void limpaTela();

int main(){

    int a, b, opcao;

    do{
        limpaTela();
        opcao = Menu();

        switch(opcao){
            case 1:
                limpaTela();
                cout << "informe o primeiro valor: ";
                cin >> a;
                cout << "informe o segundo valor: ";
                cin >> b;
                cout << "\n";
                cout << "A soma de " << a << " + " << b << " é igual a: " << Calculadora::soma(a, b) << endl;
                pause();
                break;
            case 2:
                limpaTela();
                cout << "informe o primeiro valor: ";
                cin >> a;
                cout << "informe o segundo valor: ";
                cin >> b;
                cout << "\n";
                cout << "A subtracao de " << a << " - " << b << " é igual a: " << Calculadora::subtracao(a, b) << endl;
                pause();
                break;
            case 3:
                limpaTela();
                cout << "informe o primeiro valor: ";
                cin >> a;
                cout << "informe o segundo valor: ";
                cin >> b;
                cout << "\n";
                cout << "A multiplicacao de " << a << " * " << b << " é igual a: " << Calculadora::multiplicacao(a, b) << endl;
                pause();
                break;
            case 4:
                limpaTela();
                cout << "informe o primeiro valor: ";
                cin >> a;
                cout << "informe o segundo valor: ";
                cin >> b;
                cout << "\n";
                cout << "A divisao de " << a << " / " << b << " é igual a: " << Calculadora::divisao(a, b) << endl;
                pause();
                break;
            case 5:
                limpaTela();
                cout << "informe o primeiro valor: ";
                cin >> a;
                cout << "informe o segundo valor: ";
                cin >> b;
                cout << "\n";
                cout << "A potencia de " << a << " ^ " << b << " é igual a: " << Calculadora::potencia(a, b) << endl;
                pause();
                break;
            case 6:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção invalida" << endl;
        }
    }while(opcao != 6);
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