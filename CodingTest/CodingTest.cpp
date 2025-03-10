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
    
    vector<tuple<int, int, int>> e;

    for (int i = 0; i <= M; ++i)
    {
        cin >> A >> B >> C;

        if (C == 0)
            C = 1;
        else
            C = 0;

        e.push_back({ C,A,B });
    }

    // min
    sort(e.begin(), e.end());
    int cnt = 0;
    int minSum = 0;
    p = vector<int>(N + 1, -1);

    for (int i = 0; i <= M; ++i)
    {
        auto t = e[i];
        int c, a, b;
        tie(c, a, b) = t;

        if (uni(a, b) == false)
            continue;
        
        ++cnt;
        minSum += c;
        
        if (cnt == N)
            break;
    }

    // max
    cnt = 0;
    int maxSum = 0;
    p = vector<int>(N + 1, -1);

    for (int i = M; i >= 0; --i)
    {
        auto t = e[i];
        int c, a, b;
        tie(c, a, b) = t;

        if (uni(a, b) == false)
            continue;

        ++cnt;
        maxSum += c;

        if (cnt == N)
            break;
    }

    cout << maxSum * maxSum - minSum * minSum;

    return 0;
}