# include <iostream>
# include <limits>
# include <cstring>
# include <vector>
# include <cmath>

using namespace std;

class Ponto{
    private:
        float x;
        float y;
    public:
        Ponto();
        Ponto(float _x, float _y);

        float getX();
        void setX(float x);

        float getY();
        void sety(float y);

        void le_ponto();

        float distancia(Ponto p);

        void operator=(Ponto p);

        bool operator==(Ponto p);

        Ponto operator+(Ponto p);

        string toString();
};

Ponto::Ponto(){
    x = 0;
    y = 0;
}

Ponto::Ponto(float _x, float _y){
    x = _x;
    y = _y;
}

float Ponto::getX(){
    return x;
}

void Ponto::setX(float _x){
    x = _x;
}

float Ponto::getY(){
    return y;
}

void Ponto::sety(float _y){
    y = _y;
}

void Ponto::le_ponto(){
    cout << "Informe as coordenadas do ponto: " << endl;
    cout << "Valor de X: ";
    cin >> x;
    cout << "Valor de Y: ";
    cin >> y;
}

float Ponto::distancia(Ponto p) {
    return sqrtf((pow((p.getX() - this->getX()),2)) + (pow((p.getY() - this->getY()),2)));
}

void Ponto::operator=(Ponto p){
    x = p.getX();
    y = p.getY();
}
bool Ponto::operator==(Ponto p){
    return x == p.getX() && y == p.getY();
}

Ponto Ponto::operator+(Ponto p){
    return Ponto(x + p.getX(), y + p.getY());
}
string Ponto::toString(){
    return "(X: " + to_string(x) + ", Y: " + to_string(y) + ")";
}


class Poligono{
    private:
        vector<Ponto> pontos;
    public:
        Poligono();
        Poligono(vector<Ponto> _pontos);

        vector<Ponto> getPontos();

        void setPontos(vector<Ponto> pontos);

        void addPonto(Ponto p);

        void le_addPonto();

        float perimetro();

        void operator=(Poligono p);
        
        bool operator==(Poligono p);

        Poligono operator+(Poligono p);

        string toString();
};

Poligono::Poligono(){
    this->pontos = vector<Ponto>();
}
Poligono::Poligono(vector<Ponto> _pontos){
    this->pontos = _pontos;
}

vector<Ponto> Poligono::getPontos(){
    return this->pontos;
}
void Poligono::setPontos(vector<Ponto> pontos){
    this->pontos = pontos;
}

void Poligono::addPonto(Ponto p){
    this->pontos.push_back(p);
}

void Poligono::le_addPonto(){
    cout << "Criando um poligono!!" << endl;
    char sn;
    do{
        Ponto p;
        p.le_ponto();
        pontos.push_back(p);
        cout << "Deseja inserir outro ponto(s/n)?" << endl;
        cin >> sn;
    }while (sn != 'n');
}

float Poligono::perimetro(){
    float per = 0;
    vector<Ponto>::iterator it2;
    Ponto p1, p2;

    for (auto it = pontos.begin(); it != pontos.end()-1; it++){
        it2 = it;
        advance(it2,1);
        p1 = *it;
        p2 = *it2;
        per += p1.distancia(p2);
    }

    it2 = pontos.begin();
    p1 = *it2;
    per += p1.distancia(p2);
    
    return per;
}

void Poligono::operator=(Poligono p){
    this->pontos = p.pontos;
}

bool Poligono::operator==(Poligono p){

    if (pontos.size() != p.pontos.size()){
        return false;
    }

    for (size_t i = 0; i < pontos.size(); i++){
        if (!(pontos[i] == p.pontos[i])) {
            return false;
        }
    }

    return true;
}

Poligono Poligono::operator+(Poligono p){
    Poligono novo;
    novo.pontos = this->pontos;
    
    for (Ponto p1 : p.pontos){
        novo.addPonto(p1);
    }

    return novo;
}

string Poligono::toString(){
    int tamanho = this->pontos.size();
    string aux = "Coordenadas: \n";
    for(int i = 0; i < tamanho; i++){
        aux += this->pontos[i].toString() + "\n";
    }
    return aux;
}

int main()
{
    Poligono p, p2;
    p.setPontos({Ponto(0,0),Ponto(1,0),Ponto(1,1),Ponto(0,1)});
    p2.setPontos({Ponto(1,1),Ponto(2,1),Ponto(2,2),Ponto(1,2)});
    
    cout << "Poligono 1: " << endl;
    cout << p.toString() << endl;
    cout << "Poligono 2: " << endl;
    cout << p2.toString() << endl;

    Poligono p3 = p + p2;

    cout << "Poligono 1 + Poligono 2:" << p3.toString() << endl;

    cout << "Perimetro do poligono 1: " << p.perimetro() << endl;

    cout << "Perimetro do poligono 2: " << p2.perimetro() << endl;

    cout << "Perimetro do poligono 3: " << p3.perimetro() << endl;

    p == p2 ? cout << "Poligono 1 == Poligono 2: Sim" << endl : cout << "Poligono 1 == Poligono 2: Nao" << endl;
    
    return 0;
}

