#include <iostream>
#include <limits>
#include <cstring>
#include <regex>
#include <ctime>

using namespace std;

struct Data
{
    int dia;
    int mes;
    int ano;

    string data;

    bool validarData(Data data, bool atual);

};
Data gera_data(bool atual);
// Funções de Utilidade
void pause();
void limpaTela();
void limparBuffers();

int main()
{
    limpaTela();
    Data data;
    data = gera_data(true);
    cout << data.data;
    
    return 0;
}

void pause()
{
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

void limparBuffers()
{
    // Limpa o buffer de entrada do cin
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Limpa o buffer de saída do cout
    cout.flush();
}

bool Data::validarData(Data data, bool atual){
    // Obter o tempo atual
    time_t tempoAtual = time(nullptr);

    // Converter o tempo atual para uma estrutura tm
    tm *infoTempo = localtime(&tempoAtual);

    // Obter o ano atual (adicione 1900 ao campo tm_year)
    int anoAtual = infoTempo->tm_year + 1900;

    // Verifica se o ano é válido (entre 1900 e o ano atual)
    if (atual)
    {
        if (data.ano < 1900 || data.ano > anoAtual)
        {
            return false;
        }
    }
    else
    {
        if (data.ano < 1800)
        {
            return false;
        }
    }

    // Verifica se o mês está dentro do intervalo de 1 a 12
    if (data.mes < 1 || data.mes > 12)
    {
        return false;
    }

    // Verifica o número de dias com base no mês (considerando anos bissextos)
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Verifica se é um ano bissexto
    if ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0))
    {
        diasNoMes[2] = 29; // Fevereiro tem 29 dias em anos bissextos
    }

    // Verifica se o dia está dentro do intervalo válido para o mês
    if (data.dia < 1 || data.dia > diasNoMes[data.mes])
    {
        return false;
    }

    // Se passou por todas as verificações, a data é válida
    return true;
}

// bool verifica_data(string data){
//     regex datePattern(R"(\d{2}/\d{2}/\d{4})");
//     return regex_match(data, datePattern);
// }

Data gera_data(bool atual)
{
    Data data;
    bool valido;
    do
    {
        cout << "Digite a data no formato(dd/mm/aaaa): ";
        cin >> data.dia;
        cin.ignore();
        cin >> data.mes;
        cin.ignore();
        cin >> data.ano;

        valido = data.validarData(data, atual);
        
        if (!valido)
        {
            limpaTela();
            cout << "Data inválida !!" << endl;
            cout << "Por favor, digite uma data valida!" << endl;
            limparBuffers();
        }
    } while (!valido);
    data.data = to_string(data.dia) + "/" + to_string(data.mes) + "/" + to_string(data.ano);
    return data;
}