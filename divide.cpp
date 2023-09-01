#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc == 1)
    {
        cout << "Insufficient arguments, please pass arguments" << endl;
    }else if (argc == 4)
    {
        if (strcmp(argv[1], "int") == 0)
        {
            
            int a = stoi(argv[2]);
            int b = stoi(argv[3]);
            if (b == 0)
            {
                cout << "Divisão por 0 não pode" << endl;
            }else{
                cout << a << " / " << b << " = " << a / b << endl;
            }
            
            
        }else if (strcmp(argv[1], "double") == 0){
            double a = stod(argv[2]);
            double b = stod(argv[3]);
            
            if (b == 0)
            {
                cout << "Divisão por 0 não pode" << endl;
            }else{
                cout << a << " / " << b << " = " << a / b << endl;
            }

        }else{
            cout << "Invalid operator" << endl;
        }
    }else{
        cout << "Arguments messed up, just pass: the type, the first value and the second value" << endl;
    }
    
    
    return 0;
}

