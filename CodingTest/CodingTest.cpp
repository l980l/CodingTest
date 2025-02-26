#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int adj[101][101] = {};

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> adj[i][j];
        }
    }

    int result[101][101] = {};

    for (int i = 1; i <= N; ++i)
    {
        stack<int> stack;
        vector<bool> visit(N+1);

        stack.push(i);

        while (stack.empty() == false)
        {
            int cur = stack.top();
            stack.pop();

            for (int j = 1; j <= N; ++j)
            {
                if (adj[cur][j] == 1 && visit[j] == false)
                {
                    stack.push(j);
                    visit[j] = true;
                    result[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
} 