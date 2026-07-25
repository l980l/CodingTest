#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;

    for (int tcn = 1; tcn <= t;++tcn)
    {
        cin >> n >> k;

        vector<vector<int>> board(n, vector<int>(n));
        vector<vector<bool>> visitR(n, vector<bool>(n));
        vector<vector<bool>> visitC(n, vector<bool>(n));
        for (int i = 0;i < n;++i)
        {
            for (int j = 0; j < n;++j)
            {
                cin >> board[i][j];
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n;++j)
            {
                if (board[i][j] == 0)
                    continue;

                if (!visitR[i][j])
                {
                    visitR[i][j] = true;

                    int curLine = 1;
                    int nr = i;

                    while (nr + 1 < n && board[nr + 1][j] == 1)
                    {
                        ++nr;
                        visitR[nr][j] = true;

                        ++curLine;
                    }

                    if (curLine == k)
                        ++result;
                }

                if (!visitC[i][j])
                {
                    visitC[i][j] = true;

                    int curLine = 1;
                    int nc = j;
                    while (nc + 1 < n && board[i][nc + 1] == 1)
                    {
                        ++nc;
                        visitC[i][nc] = true;

                        ++curLine;
                    }

                    if (curLine == k)
                        ++result;
                }
            }
        }

        cout << "#" << tcn << " " << result << "\n";
    }

    return 0;
}

