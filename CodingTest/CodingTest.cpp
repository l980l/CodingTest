#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> indegree(N + 1, 0);
    vector<vector<int>> adj(N + 1);

    int A, B;
    while (M--)
    {
        cin >> A >> B;
        adj[A].push_back(B);
        ++indegree[B];
    }

    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0)
            pq.push(i);
    }

    while (pq.empty() == false)
    {
        int cur = pq.top();
        result.push_back(cur);
        pq.pop();

        for (int next : adj[cur])
        {
            --indegree[next];
            
            if (indegree[next] == 0)
                pq.push(next);
        }
    }

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}