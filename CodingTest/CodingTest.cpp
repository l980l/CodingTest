#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> Board;

void func(int n, int sr, int sc)
{
    bool OneColor = true;
    int temp = Board[sr][sc];
    for (int i = sr; i < sr + n; ++i)
    {
        for (int j = sc; j < sc + n; ++j)
        {
            if (temp != Board[i][j])
                OneColor = false;
        }
    }
    if (OneColor)
    {
        cout << temp-'0';
    }
    else
    {
        cout << "(";
        func(n / 2, sr, sc);
        func(n / 2, sr, sc+n/2);
        func(n / 2, sr+n/2, sc);
        func(n / 2, sr+n/2, sc+n/2);
        cout << ")";
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
        string S;
        cin >> S;
        for (int j = 0; j < N; ++j)
        {
            Board[i][j] = S[j];
        }
    }

    func(N, 0, 0);

    return 0;
}