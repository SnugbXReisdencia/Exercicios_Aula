# include <iostream>
# include <limits>
# include <cstring>
# include <vector>

using namespace std;

class Evento{
    private:
        int duracao;
    public:
        Evento(int d){
            duracao = d;
        }
        int getDuracao(){
            return duracao;
        }
        void setDuracao(int d){
            duracao = d;
        }
};

class Pacote{
    private:
        string name;
        vector<Evento*> eventos;
    public:
        Pacote(string n){
            name = n;
        }

        void addEvento(Evento &e){
            eventos.push_back(&e);
        }

        void listaEventos(){
            cout << "Eventos de: " << name << endl;
            for(auto e : eventos){
                cout << e->getDuracao() << endl;
            }
        }
};



void pause();
void limpaTela();


int main(){
    
    Pacote p1("Pacote 1");
    Pacote p2("Pacote 2");

    Evento e1(1);
    Evento e2(2);
    Evento e3(3);
    Evento e4(4);

    p1.addEvento(e1);
    p1.addEvento(e2);
    p2.addEvento(e2);
    p2.addEvento(e3);
    p1.listaEventos();
    p2.listaEventos();
    e2.setDuracao(10);
    p1.listaEventos();
    p2.listaEventos();

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