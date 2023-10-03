# include <iostream>
# include <limits>
# include <cstring>

using namespace std;

class Senha{
    public:
        static bool ValidaSenha(string senha);
};

bool Senha::ValidaSenha(string senha){
    bool ret = true;
    if(senha.empty()) ret = false;
    if(senha.length() <= 8) ret = false;
    if(senha.length() >= 13) ret = false;
    for(char c: senha){
        if(!(c >= 'a' && c <= 'z')){ret = true; break;}
        else ret = false;
    }
    for(char c: senha){
        if(!(c >= 'A' && c <= 'Z')) {ret = true; break;}
        else ret = false;        
    }
    for(char c: senha){
        if(!(c >= '0' && c <= '9')) {ret = true; break;}
        else ret = false;
    }

    if(ret) return ret;
    else return ret;
}

void pause();
void limpaTela();

int main(){
    limpaTela();
    string senha;
    cout << "Digite uma senha: ";
    cin >> senha;

    Senha::ValidaSenha(senha) ? cout << "Senha Valida" : cout << "Senha Invalida";


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