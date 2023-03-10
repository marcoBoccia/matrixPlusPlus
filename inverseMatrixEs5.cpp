#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 5; // dimensione della matrice quadrata

int main() {
    int matrice[N][N]; // dichiarazione della matrice quadrata

    // inizializzazione della matrice con numeri casuali da 0 a 9
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrice[i][j] = rand() % 10;
        }
    }

    // stampa della matrice originale
    cout << "Matrice originale:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    // inverti le righe della matrice
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N; j++) {
            swap(matrice[i][j], matrice[N - 1 - i][j]);
        }
    }

    // stampa della matrice con le righe invertite
    cout << "Matrice con le righe invertite:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    // inverti le colonne della matrice
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(matrice[i][j], matrice[i][N - 1 - j]);
        }
    }

    // stampa della matrice con le colonne invertite
    cout << "Matrice con le colonne invertite:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    // trasponi la matrice
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(matrice[i][j], matrice[j][i]);
        }
    }

    // stampa della matrice trasposta
    cout << "Matrice trasposta:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
