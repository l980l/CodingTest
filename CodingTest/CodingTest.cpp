#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> member(N + 1);

    // 파티에서 보는 사람들을 모두 간선으로 이어주고, 진실을 아는 자를 BFS를 해야 함. 그 다음 다시 파티를 확인해야 함.
    int tn, t;
    cin >> tn;
    vector<int> know;
    while (tn--)
    {
        cin >> t;
        know.push_back(t);
    }

    vector<vector<int>> partyMember(M);

    int pn, p;
    for (int i = 0; i < M; ++i)
    {
        cin >> pn;

        while (pn--)
        {
            cin >> p;
            for (int j : partyMember[i])
            {
                member[j].push_back(p);
                member[p].push_back(j);
            }
            partyMember[i].push_back(p);
        }
    }

    queue<int> q;
    vector<bool> visit(N + 1, false);

    for (int K : know)
    {
        q.push(K);
        visit[K] = true;

        while (q.empty() == false)
        {
            int cur = q.front();
            q.pop();

            for (int next : member[cur])
            {
                if (visit[next] == true)
                    continue;
                q.push(next);
                visit[next] = true;
            }
        }
    }

    set<int> haveToAvoid;
    for (int i = 1; i <= N; ++i)
    {
        if (visit[i] == true)
        {
            haveToAvoid.insert(i);
        }
    }

    int result = M;
    for (int i = 0; i < M; ++i)
    {
        for (int j : partyMember[i])
        {
            if (haveToAvoid.find(j) != haveToAvoid.end())
            {
                --result;
                break;
            }
        }
    }

    cout << result;

    return 0;
} 