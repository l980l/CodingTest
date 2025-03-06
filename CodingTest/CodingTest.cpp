#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> result;
    vector<int> indegree(N + 1, 0);
    vector<vector<int>> adj(N + 1);

    int sn, s, prev;
    for (int i = 0; i < M; ++i)
    {
        prev = 0;
        cin >> sn;

        while (sn--)
        {
            cin >> s;

            if (prev != 0)
            {
                adj[prev].push_back(s);
                ++indegree[s];
            }

            prev = s;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (q.empty() == false)
    {
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for (int next : adj[cur])
        {
            --indegree[next];
            
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    if (result.size() != N)
        cout << 0;

    else
    {
        for (int i : result)
            cout << i << "\n";
    }

    return 0;
}