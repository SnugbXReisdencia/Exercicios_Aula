#include <iostream>

using namespace std;

int main(void)
{
    system("clear");

    int cont = 0;

    for (int i = 1; i <= 100; i++)
    {
        cont = 0;
        for (int k = 1; k <= 100; k++){
            if(i % k == 0){
                cont ++;
            }
        }
        if (cont == 2){
            cout << "O numero " << i << " é primo!" << endl;
        }
    }
    
    return 0;
}
