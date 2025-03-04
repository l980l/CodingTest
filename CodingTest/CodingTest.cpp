#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;;

    cin >> N >> M;

    // 거리
    vector<vector<int>> distance(N + 1, vector<int>(N+1, 0));
    vector<vector<int>> adj(N + 1);

    int u, v, w;
    for (int i = 1; i < N; ++i)
    {
        cin >> u >> v >> w;

        distance[u][v] = w;
        distance[v][u] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (M--)
    {
        cin >> u >> v;

        vector<bool> visit(N + 1);
        queue<int> q;
        q.push(u);
        visit[u] = true;

        while (q.empty() == false)
        {
            int cur = q.front();
            q.pop();
            
            if (cur == v)
            {
                cout << distance[u][v] << "\n";
                break;
            }

            for (int next : adj[cur])
            {
                if (visit[next] == true)
                    continue;

                visit[next] = true;
                distance[u][next] = distance[u][cur] + distance[cur][next];
                distance[next][u] = distance[u][cur] + distance[cur][next];
                q.push(next);
            }
        }
    }

    return 0;
}