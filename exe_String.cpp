#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char word[6] = {'H','e','l','l','o'};
    char name[30];

    cout << "Enter your name: ";
    cin >> name;
    // cin.getline(name, 30);
    
    cout << word << ", " << name << " !" << endl;

    int i = 0;

    // while (name[i] != '\0'){
    //     i++;
    // }

    i = strlen(name);

    cout << "Tamanho do nome: " << i << endl;
    return 0;
}
