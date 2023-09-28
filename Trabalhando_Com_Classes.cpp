# include <iostream>
# include <limits>
# include <cstring>

using namespace std;

class Livro{
    private:
        string titulo;
        string autor;
        string ano;
        string isbn;
    public:
        Livro(){
            titulo = "";
            autor = "";
            ano = "";
            isbn = "";
        }
        Livro(string _titulo, string _autor, string _ano, string _isbn){
            titulo = _titulo;
            autor = _autor;
            ano = _ano;
            isbn = _isbn;
        }
        Livro(string _titulo, string _autor){
            titulo = _titulo;
            autor = _autor;
            ano = "";
            isbn = "";
        }

        string getTitulo(){
            return titulo;
        }

        void setTitulo(string titulo){
            this->titulo = titulo;
        }
        string getAutor(){
            return autor;
        }
        void setAutor(string autor){
            this->autor = autor;
        }
        string getAno(){
            return ano;
        }
        void setAno(string ano){
            this->ano = ano;
        }

        string getIsbn(){
            return isbn;
        }

        void setIsbn(string isbn){
            this->isbn = isbn;
        }

        void toString(){
            cout << "Titulo: " << getTitulo() << endl;
            cout << "Autor: " << getAutor() << endl;
            cout << "Ano: " << getAno() << endl;
            cout << "ISBN: " << getIsbn() << endl;
        }
};

class Carro{
    private:
        string marca;
        string modelo;
        int ano;
        string placa;
    public:
        Carro(){
            marca = "";
            modelo = "";
            ano = 0;
            placa = "";
        }
        
        Carro(string _marca, string _modelo, int _ano, string _placa){
            marca = _marca;
            modelo = _modelo;
            ano = _ano;
            placa = _placa;
        }

        string getMarca(){
            return marca;
        }

        void setMarca(string marca){
            this->marca = marca;
        }
        string getModelo(){
            return modelo;
        }
        void setModelo(string modelo){
            this->modelo = modelo;
        }
        int getAno(){
            return ano;
        }
        void setAno(int ano){
            this->ano = ano;
        }
        string getPlaca(){
            return placa;
        }
        void setPlaca(string placa){
            this->placa = placa;
        }
        void toString(){
            cout << "Marca: " << getMarca() << endl;
            cout << "Modelo: " << getModelo() << endl;
            cout << "Ano: " << getAno() << endl;
            cout << "Placa: " << getPlaca() << endl;
        }
};

class Mamifero{
    private:
        string nome;
        string sexo;
        string especie;
        string habitate;
        string type;
        string idade;
    public:
        Mamifero(){
            nome = "";
            sexo = "";
            especie = "";
            habitate = "";
            type = "";
            idade = "";
        }
        Mamifero(string _nome, string _sexo, string _especie, string _habitate, string _type, string _idade){
            nome = _nome;
            sexo = _sexo;
            especie = _especie;
            habitate = _habitate;
            type = _type;
            idade = _idade;
        }
        string getNome(){
            return nome;
        }
        void setNome(string nome){
            this->nome = nome;
        }
        string getSexo(){
            return sexo;
        }
        void setSexo(string sexo){
            this->sexo = sexo;
        }
        string getEspecie(){
            return especie;
        }
        void setEspecie(string especie){
            this->especie = especie;
        }
        string getHabitate(){
            return habitate;
        }
        void setHabitate(string habitate){
            this->habitate = habitate;
        }
        string getType(){
            return type;
        }
        void setType(string type){
            this->type = type;
        }
        string getIdade(){
            return idade;
        }
        void setIdade(string idade){
            this->idade = idade;
        }
        void toString(){
            cout << "Nome: " << getNome() << endl;
            cout << "Sexo: " << getSexo() << endl;
            cout << "Especie: " << getEspecie() << endl;
            cout << "Habitat: " << getHabitate() << endl;
            cout << "Tipo: " << getType() << endl;
            cout << "Idade: " << getIdade() << endl;
        }
};

class Ave{
    private:
        string nome_cientifico;
        string especie;
        bool voar;
        string reproducao;
        string espectativa_vida;
        double peso;
        double altura;


};

void pause();
void limpaTela();

int main(){
    limpaTela();
    Livro livro1("O Senhor dos Anéis", "J.R.R Tolkien", "1954", "1234567890123");
    livro1.toString();

    cout << endl;
    Livro livro2;
    livro2.setTitulo("Arte da guerra");
    livro2.setAutor("Sun Tzu");
    livro2.setAno("500a.c");
    livro2.setIsbn("1234567890123");
    livro2.toString();

    cout << endl;
    Carro carro1("Ford", "Fiesta", 2018, "ABC123");
    carro1.toString();
    cout << endl;
    Mamifero mamifero1("Mylon", "Macho", "Cachorro", "Casa", "Terrestre", "10");
    mamifero1.toString();

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