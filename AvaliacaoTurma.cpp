#include <iostream>
#include <vector>
#include <cstring>
#include <limits>

using namespace std;

struct Aluno {
    int matricula;
    string nome;
    vector<double> notas_teoria;
    vector<double> notas_pratica;
    double media;
};

// Função para calcular a média do aluno
double calcularMedia(const Aluno& aluno) {
    double soma_teoria = 0.0;
    for (const double nota : aluno.notas_teoria) {
        soma_teoria += nota;
    }

    double soma_pratica = 0.0;
    for (const double nota : aluno.notas_pratica) {
        soma_pratica += nota;
    }

    return (2 * (soma_teoria / aluno.notas_teoria.size()) + (soma_pratica / aluno.notas_pratica.size())) / 3.0;
}

double calcularMediaTurma(const vector<Aluno>& alunos) {
    double somaMedia = 0.0;
    for (const Aluno& aluno : alunos) {
        somaMedia += aluno.media;
    }

    return somaMedia / alunos.size();
}
// Função para exibir os detalhes de um aluno
void mostrarAluno(const Aluno& aluno) {
    cout << "Matricula: " << aluno.matricula << endl;
    cout << "Nome: " << aluno.nome << endl;

    cout << "Notas Teoria: ";
    for (const double nota : aluno.notas_teoria) {
        cout << nota << "  ";
    }
    cout << endl;

    cout << "Notas Pratica: ";
    for (const double nota : aluno.notas_pratica) {
        cout << nota << "  ";
    }
    cout << endl;

    cout << "Media: " << aluno.media << endl;
    cout << endl;
}

// Função para cadastrar um aluno
Aluno cadastrarAluno(int matricula) {
    Aluno aluno;
    aluno.matricula = matricula;

    cout << "Digite o nome do aluno " << aluno.matricula << ": ";
    cin.ignore(); // Limpar o buffer
    getline(cin, aluno.nome);

    int numNotasTeoria, numNotasPratica;

    cout << "Quantas notas de Teoria deseja adicionar para o aluno " << aluno.matricula << ": ";
    cin >> numNotasTeoria;

    cout << "Digite as notas de Teoria (separadas por espaços): ";
    for (int j = 0; j < numNotasTeoria; j++) {
        double nota;
        cin >> nota;
        aluno.notas_teoria.push_back(nota);
    }

    cout << "Quantas notas de Pratica deseja adicionar para o aluno " << aluno.matricula << ": ";
    cin >> numNotasPratica;

    cout << "Digite as notas de Pratica (separadas por espaços): ";
    for (int j = 0; j < numNotasPratica; j++) {
        double nota;
        cin >> nota;
        aluno.notas_pratica.push_back(nota);
    }

    aluno.media = calcularMedia(aluno);

    return aluno;
}

void pause();
void limpaTela();

int main() {
    limpaTela();
    vector<Aluno> alunos;
    int numAlunos;

    cout << "Quantos alunos deseja cadastrar? ";
    cin >> numAlunos;

    // Cadastrar os alunos
    for (int i = 0; i < numAlunos; i++) {
        Aluno aluno = cadastrarAluno(i + 1);
        alunos.push_back(aluno);
    }

    // Calcular a média dos alunos
    for (Aluno& aluno : alunos) {
        aluno.media = calcularMedia(aluno);
    }

    // Calcular a média da turma
    double mediaTurma = calcularMediaTurma(alunos);

    cout << "Alunos Aprovados:" << endl;
    for (const Aluno& aluno : alunos) {
        if (aluno.media >= 7.0) {
            mostrarAluno(aluno);
        }
    }

    cout << "\nAlunos Reprovados:" << endl;
    for (const Aluno& aluno : alunos) {
        if (aluno.media < 7.0) {
            mostrarAluno(aluno);
        }
    }

    cout << "\nMedia da Turma: " << mediaTurma << endl;

    cout << "Alunos Acima da Media da Turma:" << endl;
    for (const Aluno& aluno : alunos) {
        if (aluno.media > mediaTurma) {
            mostrarAluno(aluno);
        }
    }

    return 0;
}

void pause() {
    cin.ignore();
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void limpaTela() {
    cin.clear();

    // Verifica se a variável de ambiente WINDIR está definida (ambiente Windows)
    const char* windir = getenv("WINDIR");
    
    if (windir != nullptr && strlen(windir) > 0) {
        // Se estiver definida, estamos no Windows, então use "cls"
        system("cls");
    } else {
        // Caso contrário, estamos em um ambiente Unix/Linux, use "clear"
        system("clear");
    }
}

