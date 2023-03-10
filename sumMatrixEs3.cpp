#include <iostream>
#include <iomanip>
#include <cstdlib> // per rand() e srand()
#include <ctime> // per time()

using namespace std;

int main()
{
    const int ROWS = 4;
    const int COLS = 4;
    int matrix[ROWS][COLS];

    // Imposta il seme del generatore di numeri casuali
    srand(time(NULL));

    // Popola la matrice con numeri casuali
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100; // genera numeri casuali tra 0 e 99
        }
    }

    // Stampa la matrice con la somma di ogni riga e colonna
    cout << "Matrice con somma di ogni riga e colonna:" << endl;
    for (int i = 0; i < ROWS; i++) {
        int row_sum = 0;
        for (int j = 0; j < COLS; j++) {
            cout << setw(4) << matrix[i][j] << " ";
            row_sum += matrix[i][j];
        }
        cout << "| " << setw(4) << row_sum << endl;
    }

    // Stampa la somma di ogni colonna
    cout << setw(5) << " ";
    for (int j = 0; j < COLS; j++) {
        cout << "----";
    }
    cout << "-----" << endl;
    for (int j = 0; j < COLS; j++) {
        int col_sum = 0;
        for (int i = 0; i < ROWS; i++) {
            col_sum += matrix[i][j];
        }
        cout << setw(4) << col_sum << " ";
    }
    cout << "| ";
    int total_sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            total_sum += matrix[i][j];
        }
    }
    cout << setw(4) << total_sum << endl;

    return 0;
}
