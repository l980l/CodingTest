#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

    int T, N, C;

    cin >> N;
    p = vector<int>(N, -1);
    vector<tuple<int, int, int>> e;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> C;
         
            if (j >= i + 1)
                e.push_back({ C,i,j });
        }
    }

    sort(e.begin(), e.end());

    int cnt = 0;
    long long result = 0;

    for (auto t : e)
    {
        int c, x, y;
        tie(c, x, y) = t;
        if (uni(x, y) == false)
            continue;

        result += c;
        ++cnt;

        if (cnt == N - 1)
            break;
    }

    cout << result;

    return 0;
}