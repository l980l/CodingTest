#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> d(V + 1, vector<int>(V + 1, 0x3f3f3f3f));

    int a, b, c;
    for (int i = 0; i < E; ++i)
    {
        cin >> a >> b >> c;
        d[a][b] = c;
    }

    for (int i = 0; i <= V; ++i)
    {
        d[i][i] = 0;
    }

    for (int k = 1; k <= V; ++k)
    {
        for (int i = 1; i <= V; ++i)
        {
            for (int j = 1; j <= V; ++j)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int minC = 0x7f7f7f7f;

    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (d[i][j] == 0x3f3f3f3f || d[j][i] == 0x3f3f3f3f || i == j)
                continue;
            minC = min(minC, d[i][j] + d[j][i]);
        }
    }

    if (minC == 0x7f7f7f7f)
        minC = -1;

    cout << minC;

    return 0;
}