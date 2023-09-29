# include <iostream>
# include <limits>
# include <cstring>

using namespace std;

class My_int{
    private:
        int num;
    public:
        My_int(){
            num = 0;
        }
        My_int(int _num){
            num = _num;
        }
        
        int getNum(){
            return num;
        }
        void setNum(int num){
            this->num = num;
        }

        int operator+(My_int x){
            return (this->num + x.getNum())+1;
        }

        void operator=(int x){
            this->num = x+1;
        }
        void operator=(My_int x){
            this->num = x.getNum()+1;
        }

};

void pause();
void limpaTela();
int main(){
    limpaTela(); // start
    My_int z;
    My_int y;

    z = y;

    cout << "O valor de Z: " << z.getNum() << endl;

    pause();
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
