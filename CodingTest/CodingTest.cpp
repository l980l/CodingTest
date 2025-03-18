#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<long long, int>>> adj(N + 1);
    vector<long long> d(N + 1, 50000000002);
    while (M--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[v].push_back({ c,u });
    }

    vector<int> place;
    while (K--)
    {
        int p;
        cin >> p;
        place.push_back(p);
        d[p] = 0;
    }

    priority_queue <pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int p : place)
    {
        pq.push({ 0, p });
    }

    while (pq.empty() == false)
    {
        long long c = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (d[cur] != c)
            continue;

        for (auto next : adj[cur])
        {
            if (d[next.second] <= c + next.first)
                continue;

            d[next.second] = c + next.first;
            pq.push({ d[next.second], next.second });
        }
    }

    long long maxCost = *max_element(d.begin() + 1, d.end());
    int index = max_element(d.begin() + 1, d.end()) - d.begin();
    cout << index << "\n";
    cout << maxCost;

    return 0;
}