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

string Ponto::toString(){
    return "(X:" + to_string(x) + ", Y:" + to_string(y) + ")";
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

string Poligono::toString(){
    int tamanho = this->pontos.size();
    string aux = "Coordenadas: \n";
    for(int i = 0; i < tamanho; i++){
        aux += this->pontos[i].toString() + "\n";
    }
    return aux;
}


