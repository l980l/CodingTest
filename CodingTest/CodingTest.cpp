#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, x, y;

bool solve(int st, vector<vector<int>>& adj)
{
    vector<bool> visit(N + 1, false);
    queue<int> q;

    q.push(st);
    visit[st] = true;

    int count = 0;
    while (q.empty() == false)
    {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur])
        {
            if (visit[next] == true)
                continue;
            q.push(next);
            visit[next] = true;
            ++count;
        }
    }

    return count >= (N + 1) / 2;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<vector<int>> heavy(N + 1);
    vector<vector<int>> light(N + 1);

    while (M--)
    {
        cin >> x >> y;

        heavy[x].push_back(y);
        light[y].push_back(x);
    }

    int result = 0;

    for (int i = 1; i <= N; ++i)
    {
        result += (solve(i, heavy) || solve(i, light));
    }

    cout << result;
    
    return 0;
} 