#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    int x, y;
    
    while (true)
    {
        cin >> x >> y;

        if (x == -1 && y == -1)
            break;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> points(n + 1, 2147483647);

    for (int i = 1; i <= n; ++i)
    {
        queue<int> queue;
        vector<int> weight(n + 1, -1);

        queue.push(i);
        weight[i] = 0;

        while (queue.empty() == false)
        {
            int cur = queue.front();
            queue.pop();

            for (int now : adj[cur])
            {
                if (weight[now] == -1)
                {
                    weight[now] = weight[cur] + 1;
                    queue.push(now);
                }
            }
        }

        points[i] = *max_element(weight.begin(), weight.end());
    }

    int r1 = *min_element(points.begin(), points.end());

    vector<int> candidate;

    for (int i = 1; i <= n; ++i)
    {
        if (r1 == points[i])
            candidate.push_back(i);
    }
    
    cout << r1 << " " << (int)candidate.size() << "\n";
    
    for (int i : candidate)
    {
        cout << i << " ";
    }

    return 0;
} 