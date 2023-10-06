#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

class Forma{
    public:
        float calcularArea();
};

class Retangulo : public Forma{
    private:
        float altura;
        float largura;
    public:
        Retangulo(float altura, float largura);
        float calcularArea();
};

Retangulo::Retangulo(float altura, float largura){
    this->altura = altura;
    this->largura = largura;
}

float Retangulo::calcularArea(){
    return altura * largura;
}

class Circulo : public Forma{
    private:
        float raio;
    public:
        Circulo(float raio);
        float calcularArea();
};

Circulo::Circulo(float raio){
    this->raio = raio;
}

float Circulo::calcularArea(){
    return M_PI * pow(raio, 2);
}

void pause();
void limpaTela();

int menu();
int main(){
    int opc;
    float alt, lar;
    vector<Retangulo> retangulos;
    vector<Circulo> circulos;
    
    do{
        limpaTela();
        opc = menu();
        limpaTela();
        switch(opc){
            case 1:
                cout << " Gerando um retangulo: " << endl;
                cout << "Informe a Altura: ";
                cin >> alt;
                cout << "Informe a Largura: ";
                cin >> lar;
                retangulos.push_back(Retangulo(alt, lar));
                cout << "Retangulo adicionado com sucesso!" << endl;
                pause();
                break;
            case 2:
                cout << " Area de todos os retangulos: " << endl;
                for(size_t i = 0; i < retangulos.size(); i++){
                    cout << "Retangulo " << i << "ª: " << endl;
                    cout << "Area: " << retangulos[i].calcularArea() << endl;
                    cout << "-------------------------" << endl;
                }
                pause();
                break;
            case 3:
                cout << " Gerando um circulo: " << endl;
                cout << "Informe o Raio: ";
                cin >> alt;
                circulos.push_back(Circulo(alt));
                cout << "Circulo adicionado com sucesso!" << endl;
                pause();
                break;
            case 4:
                cout << "Area de todos os circulos: " << endl;
                for(size_t i = 0; i < circulos.size(); i++){
                    cout << "Circulo " << i << "ª: " << endl;
                    cout << "Area: " << circulos[i].calcularArea() << endl;
                    cout << "-------------------------" << endl;
                }
                pause();
                break;
            case 0:
                break;
            default:
                cout << "Opção invalida!" << endl;
                pause();
        }
    }while(opc != 0);
    
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

