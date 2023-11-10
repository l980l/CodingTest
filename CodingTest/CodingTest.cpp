#include <iostream>
#include <vector>
using namespace std;

int Result1;
int Result2;
int Result3;
vector<vector<int>> Board;

void func(int n, int sr, int sc)
{
    int temp = Board[sr][sc];
    bool OnePiece = true;
    for (int i = sr; i < sr + n; ++i)
    {
        for (int j = sc; j < sc + n; ++j)
        {
            if (temp != Board[i][j])
                OnePiece = false;
        }
    }
    if (OnePiece)
    {
        if (temp == -1)
            Result1++;
        if (temp == 0)
            Result2++;
        if (temp == 1)
            Result3++;
    }
    else
    {
        func(n / 3, sr, sc);
        func(n / 3, sr, sc + n / 3);
        func(n / 3, sr, sc + n * 2 / 3);
        func(n / 3, sr + n / 3, sc);
        func(n / 3, sr + n / 3, sc + n / 3);
        func(n / 3, sr + n / 3, sc + n * 2 / 3);
        func(n / 3, sr + n * 2 / 3, sc);
        func(n / 3, sr + n * 2 / 3, sc + n / 3);
        func(n / 3, sr + n * 2 / 3, sc + n * 2 / 3);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    Board = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Board[i][j];
        }
    }
    Result1 = 0;
    Result2 = 0;
    Result3 = 0;
    func(N, 0, 0);
    cout << Result1 << '\n';
    cout << Result2 << '\n';
    cout << Result3 << '\n';

    return 0;
}