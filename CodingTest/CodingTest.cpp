#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define x first
#define y second

vector<int> parent;

int find(int a)
{
    if (parent[a] < 0)
        return a;
    return parent[a] = find(parent[a]);
}

bool uni(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return false;

    parent[b] = a;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> G(N + 1);
    vector<tuple<long long, int, int>> e;

    for (int i = 1; i <= N; ++i)
    {
        cin >> G[i].x >> G[i].y;
        for (int j = 1; j < i; ++j)
        {
            long long Xdis = G[i].x - G[j].x;
            long long Ydis = G[i].y - G[j].y;
            long long distance = Xdis * Xdis + Ydis * Ydis;

            e.push_back({ distance, i, j });
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int tmp1, tmp2;

        cin >> tmp1 >> tmp2;
        e.push_back({ 0, tmp1, tmp2 });
    }

    parent = vector<int>(N + 1, -1);

    sort(e.begin(), e.end());

    int cnt = 0;
    double result = 0;

    for (const auto& p : e)
    {
        long long c;
        int u, v;
        tie(c, u, v) = p;

        if (uni(u, v) == false)
            continue;

        ++cnt;
        result += sqrt(c);

        if (cnt == N - 1)
            break;
    }

    cout << fixed;
    cout.precision(2);
    cout << result;

    return 0;
}