#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    for (int i = 0; i <= n; ++i)
    {
        d[i][i] = 0;
    }

    int u, v, b;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> b;
        
        d[u][v] = 0;
        d[v][u] = b == 0 ? 1 : 0;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cin >> m;
    while (m--)
    {
        cin >> u >> v;
        cout << d[u][v] << "\n";
    }

    return 0;
}