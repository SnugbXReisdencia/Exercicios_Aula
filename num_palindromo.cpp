# include <iostream>

using namespace std;

int main(void) {

    system("clear");

    int valor_digitado, valor_invertido, valor, resto;
    
    cout << "Informe uma valor" << endl;
    cin >> valor_digitado;

    valor = valor_digitado;
    valor_invertido = 0;

    while(valor != 0)
    {
        resto = valor % 10;
        valor_invertido = (valor_invertido * 10) + resto;
        valor = valor / 10;
    }

    // cout << "Valor Inverso: " << valor_invertido << endl;

    if (valor_digitado == valor_invertido){
        cout << valor_digitado << " é um palindromo." << endl;
    }else{
        cout << valor_digitado << " não é um palindromo." << endl;
    }
    
    return 0;
    
}