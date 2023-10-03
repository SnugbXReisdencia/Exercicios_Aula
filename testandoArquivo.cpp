# include <iostream>
# include <fstream>
# include <limits>
# include <cstring>
# include <vector>

using namespace std;

class BancoDeDados{
    public:
        static bool saveDados(vector<string> dados);
        static vector<string> recuperarDados();
};

bool BancoDeDados::saveDados(vector<string> dados){
    ofstream arquivo("dados.txt"); 
    if(arquivo.is_open()){
        for(int i = 0; i < dados.size(); i++){
            arquivo << dados[i] << endl;
        }
    }
    arquivo.close();
    return true;
}

vector<string> BancoDeDados::recuperarDados(){
    vector<string> dados;
    ifstream arquivo("dados.txt");
    if(arquivo.is_open()){
        string linha;
        while(getline(arquivo, linha)){
            dados.push_back(linha);
        }
    }
    arquivo.close();
    return dados;
}
void pause();
void limpaTela();

int main(){
    limpaTela();
    vector<string> dados;
    dados = BancoDeDados::recuperarDados();
    cout << "Dados: " << endl;
    for(size_t i = 0; i < dados.size(); i++){
        cout << dados[i] << endl;
    }

    cout << "Novos dados: " << endl;
    string novo;
    cin >> novo;
    dados.push_back(novo);

    BancoDeDados::saveDados(dados);

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