#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, E;
    int a, b, c;
    cin >> N >> E;

    vector<vector<pair<int, int>>> adj(N + 1);
    vector<int> d(N + 1, 0x3f3f3f3f);

    // a b 사이의 최단 경로 구하고, (1-a + b-n)과 (1-b + a-n)를 비교해서 더 낮은 경로를 선택하면 될 듯?
    while (E--)
    {
        cin >> a >> b >> c;

        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }

    cin >> a >> b;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    long long abSum = 0;
    long long baSum = 0;

    // a에서 다익스트라
    d = vector<int>(N + 1, 0x3f3f3f3f);
    d[a] = 0;
    pq.push({ 0, a });

    while (pq.empty() == false)
    {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.second] != cur.first)
            continue;

        for (auto next : adj[cur.second])
        {
            if (d[next.second] <= d[cur.second] + next.first)
                continue;
            
            d[next.second] = d[cur.second] + next.first;
            pq.push({ d[next.second], next.second });
        }
    }

    abSum += d[1] + d[b];
    baSum += d[N];

    // b에서 다익스트라
    d = vector<int>(N + 1, 0x3f3f3f3f);
    d[b] = 0;
    pq.push({ 0, b });

    while (pq.empty() == false)
    {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.second] != cur.first)
            continue;

        for (auto next : adj[cur.second])
        {
            if (d[next.second] <= d[cur.second] + next.first)
                continue;

            d[next.second] = d[cur.second] + next.first;
            pq.push({ d[next.second], next.second });
        }
    }

    abSum += d[N];
    baSum += d[1] + d[a];

    if (abSum >= 0x3f3f3f3f && baSum >= 0x3f3f3f3f)
        cout << -1;
    else
        cout << min(abSum, baSum);

    return 0;
}