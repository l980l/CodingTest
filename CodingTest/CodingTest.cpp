#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;

    cin >> n >> m;

    vector<vector<int>> graph(n+1);

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int result = 0;

    queue<int> queue;
    vector<int> visit(n + 1, -1);

    queue.push(1);
    visit[1] = 0;

    while (queue.empty() == false)
    {
        int cur = queue.front();
        queue.pop();

        for (int i : graph[cur])
        {
            if (visit[i] == -1)
            {
                if (visit[cur] <= 1)
                {
                    visit[i] = visit[cur] + 1;
                    queue.push(i);
                    ++result;
                }
            }
        }
    }

    cout << result;

    return 0;
} 