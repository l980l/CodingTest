#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e;

    cin >> v >> e;

    vector<vector<int>> graph(v + 1);
    
    int x, y;

    for (int i = 0; i < e; ++i)
    {
        cin >> x >> y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int result = 0;

    vector<bool> visit(v + 1, false);
    queue<int> queue;

    visit[1] = true;
    queue.push(1);

    while (queue.empty() == false)
    {
        int now = queue.front();
        queue.pop();

        for (int i : graph[now])
        {
            if (visit[i] == false)
            {
                visit[i] = true;
                queue.push(i);
                result += 1;
            }
        }
    }

    cout << result;

    return 0;
} 