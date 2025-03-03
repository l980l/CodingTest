#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m, x, y;
vector<vector<int>> adj;
vector<bool> visit;
stack<int> s;
bool isCycle;

void dfs(int cur, int parent)
{
    for (int next : adj[cur])
    {
        if (next == parent)
            continue;
        if (visit[next] == true)
        {
            isCycle = true;
            continue;
        }
        visit[next] = true;
        dfs(next, cur);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int caseCount = 0;
    while (true)
    {
        ++caseCount;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        adj = vector<vector<int>>(n + 1);
        visit = vector<bool>(n + 1, false);

        while (m--)
        {
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int T = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (visit[i] == false)
            {
                isCycle = false;
                
                visit[i] = true;
                dfs(i, -1);

                if (isCycle == false)
                    ++T;
            }
        }

        cout << "Case " << caseCount << ": ";
        if (T == 0)
            cout << "No trees." << '\n';
        else if (T == 1)
            cout << "There is one tree." << '\n';
        else
            cout << "A forest of " << T << " trees." << '\n';
    }

    return 0;
}