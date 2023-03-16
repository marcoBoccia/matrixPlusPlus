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

int mossaPensata(char *tab)
{
    int risultato = -1;
    char vuoto = '_';

    // QUI LAVORO
    int combinazioni[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];

        bool condizione = a == b && c == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][2];
        }
    }

    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];

        bool condizione = c == b && a == vuoto && c == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][0];
        }
    }

    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];
        bool condizione = a == c && b == vuoto && c == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][2];
        }
    }
    /* controllo se il CPU può vincere
        se ci sono due O metto il terzo
    */
   for (int i = 0; i < 8; i++)
   {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];
        bool condizione = a == b && c == vuoto && a == 'O';

        if (condizione)
        {
            risultato = combinazioni[i][0];
        }
   }
   for (int i = 0; i < 8; i++)
   {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];
        bool condizione = a == c && b == vuoto && c == 'O';

        if (condizione)
        {
            risultato = combinazioni[i][1];
        }
   }
   return risultato;
}

int isWinner(char *arr)
{
    char vuoto = '_';

    int combinazioni[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

    for (int i = 0; i < 8; i++)
    {
        int a = arr[combinazioni[i][0]];
        int b = arr[combinazioni[i][1]];
        int c = arr[combinazioni[i][2]];
        if (a != vuoto && a == b && b == c)
        {
            return 1;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == vuoto)
        {
            return 0; // c'è ancora spazio
        }
    }

    return -1;
}

int main()
{

    char vuoto = '_';

    // inizializzo la tabella
    char tabella[9];
    for (int i = 0; i < 9; i++)
    {
        tabella[i] = vuoto;
    }
    stampa(tabella);

    bool xIsNext = true; // gestisce il turno
    while (true)         // i turni del gioco
    {

        int mossa;

        if (!xIsNext) // COMPUTER
        {
            mossa = mossaPensata(tabella);

            // while (tabella[mossa] != vuoto || (!(0 <= mossa && mossa < 9))) // controllo 2 condizioni (valido e vuoto)
            // {
            //     mossa = random() % 10;
            // }
        }
        else // UTENTE
        {
            cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
            cin >> mossa;
            mossa--; // per capirci ;)

            while (tabella[mossa] != vuoto || (!(0 <= mossa && mossa < 9))) // controllo 2 condizioni (valido e vuoto)
            {
                cout << "Non puoi inserire qui" << endl;
                cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
                cin >> mossa;
                mossa--; // per capirci ;)
            }
        }

        // se sono arrivato qui è solo perchè l'utente ha inserito un numero corretto
        xIsNext ? tabella[mossa] = 'X' : tabella[mossa] = 'O'; // se è vero metti X altrimenti metti O

        stampa(tabella);

        if (isWinner(tabella) == 1)
        {
            cout << "Hai vinto " << (xIsNext ? 'X' : 'O') << endl;
            break;
        }
        else if (isWinner(tabella) == -1)
        {
            cout << "Pareggio" << endl;
            // reset del gioco
            for (int i = 0; i < 9; i++)
            {
                tabella[i] = vuoto;
            }
            xIsNext = true;
            stampa(tabella);
        }
        else if (isWinner(tabella) == 0)
        {
            xIsNext = !xIsNext; // cambio giocatore
        }
        else
        {
            cout << "Errore nella funzione isWinner" << endl;
        }
    }
}