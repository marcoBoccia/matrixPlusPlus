#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int DIM_MATRICE = 5; // Dimensione della matrice
    int matrice[DIM_MATRICE][DIM_MATRICE]; // Matrice
    int vettoreRisultato[DIM_MATRICE * DIM_MATRICE]; // Vettore risultato
    int indiceVettore = 0; // Indice del vettore risultato

    // Generazione della matrice con numeri random 0-9
    srand(time(NULL));
    for (int i = 0; i < DIM_MATRICE; i++) {
        for (int j = 0; j < DIM_MATRICE; j++) {
            int numero_random = rand() % 10;
            matrice[i][j] = numero_random;
            if (numero_random % 3 == 0) {
                vettoreRisultato[indiceVettore] = numero_random;
                indiceVettore++;
            }
        }
    }

    // Stampa della matrice e del vettore risultato
    cout << "Matrice:" << endl;
    for (int i = 0; i < DIM_MATRICE; i++) {
        for (int j = 0; j < DIM_MATRICE; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "Numeri divisibili per 3:" << endl;
    for (int i = 0; i < indiceVettore; i++) {
        cout << vettoreRisultato[i] << " ";
    }
    cout << endl;

    return 0;
}
