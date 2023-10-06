# include <iostream>
# include <cstring>

using namespace std;

class Animal{
    private:
        string nome;
        int idade;
    public:
        Animal(string nome, int idade);
        string fazerSom();
        string getNome();
        int getIdade();
};

Animal::Animal(string nome, int idade){
    this->nome = nome;
    this->idade = idade;
}

string Animal::getNome(){
    return nome;
}

int Animal::getIdade(){
    return idade;
}

class Cachorro : public Animal{
    public:
        Cachorro(string nome, int idade);
        string fazerSom();
};

Cachorro::Cachorro(string nome, int idade) : Animal(nome, idade){}


string Cachorro::fazerSom(){
    return "au au";
}

class Gato : public Animal{
    public:
        Gato(string nome, int idade);
        string fazerSom();
};

Gato::Gato(string nome, int idade) : Animal(nome, idade){}

string Gato::fazerSom(){
    return "miau";
}

int main(){
    Cachorro cachorro("lulu", 2);
    cout << "Animal cachorro:" << endl;
    cout << cachorro.getNome() << endl;
    cout << cachorro.getIdade() << endl;
    cout << cachorro.fazerSom() << endl;

    cout << "Animal gato:" << endl;
    Gato gato("rex", 5);
    cout << gato.getNome() << endl;
    cout << gato.getIdade() << endl;
    cout << gato.fazerSom() << endl;
}