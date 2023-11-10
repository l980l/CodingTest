#include <iostream>
#include <vector>
using namespace std;
int Blue;
int White;
vector<vector<int>> Board;

void func(int n, int sr, int sc)
{
    bool OneColor = true;
    int temp = Board[sr][sc];
    for (int i = sr; i < sr + n; ++i)
    {
        for (int j = sc; j < sc + n; ++j)
        {
            if (Board[i][j] != temp)
                OneColor = false;
        }
    }
    if (OneColor)
    {
        if (temp)
            Blue++;
        else
            White++;
    }
    else
    {
        func(n / 2, sr, sc);
        func(n / 2, sr, sc+n/2);
        func(n / 2, sr+n/2, sc);
        func(n / 2, sr+n/2, sc+n/2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Blue = 0;
    White = 0;
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
    func(N, 0, 0);

    cout << White << '\n';
    cout << Blue << '\n';

    return 0;
}