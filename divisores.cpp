#include <iostream>

using namespace std;

int main(void)
{
    int value;

    cout << "Enter a number: ";
    cin >> value;

    for (int i = 1; i <= value; i++){
        if (value % i == 0)
        {
            cout << value << " é divisible by " << i << endl;
            
        }
    }
    
    return 0;
}
