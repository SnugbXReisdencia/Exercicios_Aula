# include <iostream>
# include <limits>
# include <cstring>

using namespace std;

void pause();
void limpaTela();

class Desenhavel{
    public:
        virtual void desenhar() = 0;
};

class Circulo: public Desenhavel{
    private:
        float raio;
    public:
        Circulo(float raio){
            this->raio = raio;
        }
        void desenhar(){
            for (int i = -raio; i <= raio; i++) {
                for (int j = -raio; j <= raio; j++) {
                    if (i * i + j * j-5 <= raio * raio) {
                        cout << "* ";
                    } else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
        }
};

class Retangulo: public Desenhavel{
    private:
        float altura;
        float largura;
    public:
        Retangulo(float altura, float largura){
            this->altura = altura;
            this->largura = largura;
        }
        void desenhar(){
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
                    cout << "* ";
                }
                cout << endl;
            }
        }
};

class Triangulo: public Desenhavel{
    private:
        float base;
        float altura;
    public:
        Triangulo(float base, float altura){
            this->base = base;
            this->altura = altura;
        }
        void desenhar(){
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < altura - i - 1; j++) {
                    cout << "  ";
                }
                for (int j = 0; j < 2 * i + 1; j++) {
                    cout << "* ";
                }
                cout << endl;
            }
        }
};

int main(){
    limpaTela();
    Circulo c(5);
    cout << "#### CIRCULO ######\n\n";
    c.desenhar();

    cout << "\n\n\n";

    cout << "#### RETANGULO ######\n\n";
    Retangulo r(5, 5);
    r.desenhar();

    cout << "\n\n\n";

    cout << "#### TRIANGULO ######\n\n";
    Triangulo t(5, 5);
    t.desenhar();

    pause();
    return 0;
}

void pause()
{
    // cin.ignore();
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