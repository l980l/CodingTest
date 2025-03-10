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

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    p[v] = u;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, A, B, C;
    cin >> N >> M;
    
    if (N == 2)
    {
        cout << 0;
        return 0;
    }

    p = vector<int>(N, -1);
    vector<tuple<int, int, int>> e;

    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;
        e.push_back({ C, A, B });
    }

    sort(e.begin(), e.end());

    int result = 0;
    int cnt = 0;

    for (int i = 0; i < M; ++i)
    {
        auto t = e[i];

        int c, a, b;
        tie(c, a, b) = t;

        if (uni(a, b) == false)
            continue;

        ++cnt;
        result += c;

        if (cnt == N - 2)
            break;
    }

    cout << result;

    return 0;
}