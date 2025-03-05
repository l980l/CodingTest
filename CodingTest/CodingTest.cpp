#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> child;
vector<int> score;

void dfs(int cur)
{
    for (int next : child[cur])
    {
        score[next] += score[cur];
        dfs(next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    child = vector<vector<int>>(n + 1);
    score = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int temp;
        cin >> temp;

        if (temp == -1)
            continue;

        child[temp].push_back(i);
    }

    int i, w;
    while (m--)
    {
        cin >> i >> w;
        score[i] += w;
    }

    dfs(1);

    for (int l = 1; l <= n; ++l)
    {
        cout << score[l] << " ";
    }

    return 0;
}