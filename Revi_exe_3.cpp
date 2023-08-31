#include <iostream>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <cctype>


using namespace std;

int main(void)
{
    system("clear");
    // Vrificando tamanho maximo e minimo suportados pelos tipos de dados float e double..

    // cout << "Tamanho maximo que uma variavel do tipo float suporta e : " << FLT_MAX << endl;

    // cout << "Tamanho minimo que uma variavel do tipo float suporta e : " << FLT_MIN << endl;

    // cout << "Tamanho maximo que uma variavel do tipo double suporta e : " << DBL_MAX << endl;

    // cout << "Tamanho minimo que uma variavel do tipo double suporta e : " << DBL_MIN << endl;

    // Mostrando a pressisão maxima suportada das variaveis dos tipos float, double e long double, usando o valor de PI

    // float pif = M_PIl;
    // double  dif = M_PIl;
    // double long lpif = M_PIl;

    // cout << "O valor de pi e : " << setprecision(23) << pif << " em float" << endl; 

    // cout << "O valor de pi e : " << setprecision(49) << dif << " em Double." << endl;

    // cout << "O valor de pi e : " << setprecision(63) << lpif << " em double long." << endl;


    // cout << "O valor de pi e : " << setprecision(2) << pif << " em float" << endl;
    // cout << "O valor de pi e : " << setprecision(4) << pif << " em float" << endl;
    // cout << "O valor de pi e : " << setprecision(8) << pif << " em float" << endl;
    // cout << "O valor de pi e : " << setprecision(16) << pif << " em float" << endl;

    // char ch1;
    // string tipo;

    // cout << "Digite um caractere: ";
    // cin >> ch1;

    // tipo = isupper(ch1) ? "E uma letra Maiuscula." : islower(ch1) ? "E uma letra Minuscula." 
    //      : isdigit(ch1) ? "E um digito." :  "Outro caracter.";

    // cout << tipo << endl;

    // cout << "Digite outro caractere: ";
    // cin >> ch2;

    // cout << "Digite mais um caractere: ";
    // cin >> ch3;

    // cout << ch1 << ch2 << ch3 << endl;

    int num1, num2, res=0, i=0, s, s1 = 1, s2 = 1;

    cout << "Digite um numero: ";
    cin >> num1;

    cout << "Digite outro numero: ";
    cin >> num2;
    
    if(num1 < 0){
        num1 = -num1;
        s1 = -1;
    }

    if(num2 < 0){
        num2 = -num2;
        s2 = -1;
    }
    s = s1 * s2;
    while(i< num2){
        res += num1;
        i++;
    }

    cout << "Resultado " << res*s << endl;


    return 0;
}
