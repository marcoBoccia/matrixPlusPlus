#include <iostream>
using namespace std;

void stampa(char *tab)
{
    for (int i = 0; i < 9; i++)
    {
        cout << tab[i] << " ";
        if (i == 2 || i == 5 || i == 8) // alla fine di ogni riga (3x3) vai a capo
        {
            cout << endl;
        }
    }

    cout << endl;
    cout << endl;
    cout << endl;
}

int main()
{
    
}