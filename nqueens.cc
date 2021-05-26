#include <iostream>
#include <string>

using namespace std;

int Board[16];
int Count = 0;
int n;

void queen(int row, int n);

void Print(int n) {
    int i,j;
    string Header = "*ABCDEFGHIJKLMNOP";

    cout << "solution: " << ++Count << '\n';

    for (int i = 0; i <= n; i++)
        cout << Header[i] << ' ';

    for (i = 1; i<=n; ++i)
    {
        cout << '\n' << Header[i] << ' ';
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
    if (argc != 2)
        cout << "please provide argument" << '\n';
    else
        n = atoi(argv[1]);

    if (4 > n || n > 16 || argc != 2)
    {
        cout << "Use number between 4 and 17" << '\n';
    }
    else
    {
        cout << n << "Queens Problem Recursive" << '\n';
        Queen(1, n);
    }

    return 0;
}
