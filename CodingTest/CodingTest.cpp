#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int k, v, e;
int gr[20001] = {};
vector<int> adj[20001];

bool solve()
{
    fill(gr, gr + v + 1, -1);

    for (int i = 1; i <= v; ++i)
    {
        if (gr[i] != -1)
            continue;

        queue<int> q;

        q.push(i);
        gr[i] = 0;

        while (q.empty() == false)
        {
            int cur = q.front();
            q.pop();

            for (int next : adj[cur])
            {
                if (gr[next] != -1)
                {
                    if (gr[next] == gr[cur])
                        return false;
                    else continue;
                }
                gr[next] = (gr[cur] + 1) % 2;
                q.push(next);
            }
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    while (k--)
    {
        cin >> v >> e;

        for (int i = 1; i <= v; ++i)
        {
            adj[i].clear();
        }

        int i, j;
        while (e--)
        {
            cin >> i >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        if (solve() == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
} 