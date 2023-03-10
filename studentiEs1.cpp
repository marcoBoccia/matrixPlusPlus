#include <iostream>

using namespace std;

int main() {
    const int NUM_STUDENTI = 5; // Numero di studenti
    const int NUM_PROVE = 3; // Numero di prove
    int voti[NUM_STUDENTI][NUM_PROVE]; // Matrice per memorizzare i voti

    // Ciclo per acquisire i voti degli studenti
    for (int i = 0; i < NUM_STUDENTI; i++) {
        cout << "Inserisci i voti dello studente " << i + 1 << ":" << endl;
        for (int j = 0; j < NUM_PROVE; j++) {
            cout << "Prova " << j + 1 << ": ";
            cin >> voti[i][j];
        }
    }

    // Ciclo per stampare i voti degli studenti
    cout << endl << "Voti degli studenti:" << endl;
    for (int i = 0; i < NUM_STUDENTI; i++) {
        cout << "Studente " << i + 1 << ": ";
        for (int j = 0; j < NUM_PROVE; j++) {
            cout << voti[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
