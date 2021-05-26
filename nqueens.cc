#include <iostream>
#include <string>

#define HEADER "*ABCDEFGHIJKLMNOP"

using namespace std;

int Board[16];
int Count = 0;
int N;

void queen(int row, int n);

void Print(int n) {
    int i,j;

    cout << "solution: " << ++Count << '\n';

    for (int i = 0; i <= n; i++)
        cout << HEADER[i] << ' ';

    for (i = 1; i<=n; ++i)
    {
        cout << '\n' << HEADER[i] << ' ';
        for (j = 1; j <= n; j++)
            if(Board[i] == j)
                cout << "Q ";
            else
                cout << "- ";
    }

    cout << '\n';
}

int Place(int row, int col) {
    for (int i = 1; i <= row - 1; ++i)
        if (Board[i] == col)
            return 0;
        else
            if (abs(Board[i] - col) == abs(i - row))
                return 0;
    return 1;
}

void Queen(int row, int n) {
    for (int col = 1; col <= n; ++col)
    {
        if(Place(row, col))
        {
            Board[row] = col;

	    if (row == n)
             	Print(n);
            else
                Queen(row + 1,n);
        }
    }
}

int main(int argc, char *argv[]) {
    /*
    if (argc != 2)
        cout << "please provide argument" << '\n';
    else
        n = atoi(argv[1]);
        */

    if (argc == 2) {
        N = atoi(argv[1]);

        if (N >= 5 && N <= 16) {
            cout << N << " Queens Problem Recursive" << endl;
            Queen(1, N);
        } else {
            cout << "Use number between 4 and 17" << endl;
        }
    } else {
        cout << "Missing param1 (N)" << endl;
    }

    return 0;
}
