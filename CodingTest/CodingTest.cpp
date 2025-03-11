#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return false;

    p[b] = a;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K, u, v, w;
    cin >> N >> M >> K;

    p = vector<int>(N + 1, -1);
    vector<tuple<int, int, int>> e;

    int cnt = 0;

    int prev;
    cin >> prev;
    for (int i = 1; i < K; ++i)
    {
        cin >> u;
        uni(prev, u);
        ++cnt;
        prev = u;
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> u >> v >> w;
        e.push_back({ w,u,v });
    }

    sort(e.begin(), e.end());

    int result = 0;

    for (auto cur : e)
    {
        tie(w, u, v) = cur;

        if (uni(u, v) == false)
            continue;

        result += w;
        ++cnt;
        if (cnt == N - 1)
            break;
    }

    cout << result;

    return 0;
}