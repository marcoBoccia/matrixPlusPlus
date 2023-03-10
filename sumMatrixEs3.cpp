#include <iostream>

using namespace std;

int main()
{
    const int ROWS = 4;
    const int COLS = 4;
    int matrix[ROWS][COLS];

    // Leggi la matrice da input
    cout << "Inserisci i valori della matrice 4x4:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> matrix[i][j];
        }
    }

    // Stampa la matrice originale con la somma di ogni riga e colonna
    cout << "Matrice con somma di ogni riga e colonna:" << endl;
    for (int i = 0; i < ROWS; i++) {
        int row_sum = 0;
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
            row_sum += matrix[i][j];
        }
        cout << "| " << row_sum << endl;
    }

    // Stampa la somma di ogni colonna
    cout << " ";
    for (int j = 0; j < COLS; j++) {
        cout << "----";
    }
    cout << "----" << endl;
    for (int j = 0; j < COLS; j++) {
        int col_sum = 0;
        for (int i = 0; i < ROWS; i++) {
            col_sum += matrix[i][j];
        }
        cout << col_sum << " ";
    }
    cout << "| ";
    int total_sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            total_sum += matrix[i][j];
        }
    }
    cout << total_sum << endl;

    return 0;
}
