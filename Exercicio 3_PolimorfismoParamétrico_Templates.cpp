# include <iostream>
# include <limits>
# include <cstring>
# include <vector>

using namespace std;

void pause();
void limpaTela();

template <typename T> class ListaGenerica {
    private:
        vector<T> lista;
    public:
        ListaGenerica();

        void addElemento(T);

        void removeElemento(T);

        void listar();
};

template <typename T> ListaGenerica<T>::ListaGenerica() {
    
}

template <typename T> void ListaGenerica<T>::addElemento(T elemento) {
    lista.push_back(elemento);
}

template <typename T> void ListaGenerica<T>::removeElemento(T elemento) {
    int tamanho = lista.size();
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            lista.erase(lista.begin() + i);
            break;
        }
    }
}

template <typename T> void ListaGenerica<T>::listar() {
    int tamanho = lista.size();
    for (int i = 0; i < tamanho; i++) {
        cout << lista[i] << endl;
    }
}

int main(){
    limpaTela();
    ListaGenerica<int> listaInt;
    ListaGenerica<float> listaFloat;
    ListaGenerica<char> listaChar;
    ListaGenerica<string> listaString;

    cout << "Lista de int" << endl;

    listaInt.addElemento(1);
    listaInt.addElemento(2);
    listaInt.addElemento(3);
    listaInt.addElemento(4);
    listaInt.addElemento(5);
    listaInt.addElemento(6);

    listaInt.listar();
    cout << "Removendo o elemento 5" << endl;
    listaInt.removeElemento(5);
    cout << endl;
    listaInt.listar();
    cout << endl;
    cout << "Lista de float" << endl;

    listaFloat.addElemento(1.1);
    listaFloat.addElemento(2.2);
    listaFloat.addElemento(3.3);

    listaFloat.listar();
    cout << "Removendo o elemento 1.1" << endl;
    listaFloat.removeElemento(1.1);
    listaFloat.listar();

    cout << endl;

    cout << "lista de char" << endl;

    listaChar.addElemento('a');
    listaChar.addElemento('b');
    listaChar.addElemento('c');

    listaChar.listar();

    cout << "Removendo o elemento 'a'" << endl;
    listaChar.removeElemento('a');
    listaChar.listar();

    cout << endl;

    cout << "lista de string" << endl;

    listaString.addElemento("ana");
    listaString.addElemento("beto");
    listaString.addElemento("carol");

    listaString.listar();

    cout << "Removendo o elemento 'ana'" << endl;

    listaString.removeElemento("ana");

    listaString.listar();

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