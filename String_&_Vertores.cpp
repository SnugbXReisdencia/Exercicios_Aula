#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    // system("clear");
    vector<int> vet;
    int valor, soma = 0;
    char opc;

    do
    {
        system("clear");
        cout << "Digite um valor: ";
        cin >> valor;
        vet.push_back(valor);
        soma += valor;
        cout << "Deseja adicionar mais valor (S/N): ";
        cin >> opc;
    } while (opc != 'n' && opc != 'N');
    
    cout << "{";
    
    for (int i : vet){
        cout << i << ", ";
    }
    
    cout << "} " << endl;

    cout << "A media dos valores é: " << soma/vet.size() << endl;

    return 0;
    
    // string nome;
    // vector<string> vc;

    // vc.push_back("Zangado");
    // vc.push_back("Feliz");
    // vc.push_back("Atchim");
    // vc.push_back("Mestre");
    // vc.push_back("Soneca");
    // vc.push_back("Dengoso");
    // vc.push_back("Dunga");

    // for (auto x = vc.begin(); ; i++)
    // {
    //     /* code */
    // }
    


    // char nome[10] = "oi Mundo";
    // char x;
    // nome[10] = 'G';
    // cout << x << endl;




    return 0;
}
