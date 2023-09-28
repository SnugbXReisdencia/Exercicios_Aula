# include <iostream>
# include <limits>
# include <cstring>
# include <vector>

using namespace std;

class Ponto{
    private:
        double x;
        double y;
    public:
        Ponto(){
            x = 0;
            y = 0;
        }
        Ponto(double _x, double _y){
            x = _x;
            y = _y;
        }
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
        void setX(double x){
            this->x = x;
        }
        void setY(double y){
            this->y = y;
        }
        string toString(){
            return "(X:" + to_string(x) + ", Y:" + to_string(y) + ")";
        }
};

class Poligono{
    private:
        vector<Ponto> pontos;
    public:
        Poligono();
        Poligono(vector<Ponto> _pontos);

        vector<Ponto> getPontos();

        void setPontos(vector<Ponto> pontos);

        void addPonto(Ponto p);

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

string Poligono::toString(){
    int tamanho = this->pontos.size();
    string aux = "Coordenadas: \n";
    for(int i = 0; i < tamanho; i++){
        aux += this->pontos[i].toString() + "\n";
    }
    return aux;
}


