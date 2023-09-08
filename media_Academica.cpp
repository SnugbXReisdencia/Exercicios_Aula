#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> aluno;
    vector<vector<int>> boletin;
    char opc;
    int valor;

    do
    {
        system("clear");

        cout << "Digite a matricula: ";
        cin >> valor;
        aluno.insert(aluno.begin(),valor);

        cout << "Digite a primeira nota: ";
        cin >> valor;
        
        aluno.insert(aluno.begin()+1,valor);
        cout << "Digite a segunda nota: ";
        cin >> valor;
        aluno.insert(aluno.begin()+2,valor);

        cout << "Digite a terceira nota: ";
        cin >> valor;
        aluno.insert(aluno.begin()+3,valor);

        boletin.push_back(aluno);

        cout << "Deseja continuar? [S/N]: ";
        cin >> opc;

    } while (opc != 'N' && opc != 'n');
    
    for (int i = 0; i < boletin.size(); i++){
        cout << "Matricula  Nota1   Nota2   Nota3   Media" << endl;
        cout << "================================================" << endl;
        cout << "   " <<boletin[i][0] << "   ||   " << boletin[i][1] << "   ||   " << boletin[i][2]
         << "   ||   " << boletin[i][3] << "   ||   " << (boletin[i][1] + boletin[i][2] + boletin[i][3]) / 3 << endl;
    }
    
    return 0;
}
