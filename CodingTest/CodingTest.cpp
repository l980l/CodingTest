#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, P, L, G, M;
    pair<int, int> PN[100001];
    set<int> PL[101];
    set<int> PG[101][101];

    cin >> N;

    while(N--)
    {
        cin >> P >> L >> G;
        PN[P] = { L,G };
        PL[L].insert(P);
        PG[G][L].insert(P);
    }

    cin >> M;
    string op;
    int x;
    while (M--)
    {
        cin >> op;
        
        if (op == "recommend")
        {
            cin >> G >> x;
            if (x == 1)
            {
                for (int i = 100; i >= 1; --i)
                {
                    if (PG[G][i].empty() == false)
                    {
                        cout << *(prev(PG[G][i].end())) << "\n";
                        break;
                    }
                }
            }
            else
            {
                for (int i = 1; i < 101; ++i)
                {
                    if (PG[G][i].empty() == false)
                    {
                        cout << *PG[G][i].begin() << "\n";
                        break;
                    }
                }
            }
        }

        else if (op == "recommend2")
        {
            cin >> x;
            if (x == 1)
            {
                for (int i = 100; i >= 1; --i)
                {
                    if (PL[i].empty() == false)
                    {
                        cout << *(prev(PL[i].end())) << "\n";
                        break;
                    }
                }
            }

            else
            {
                for (int i = 1; i <= 100; ++i)
                {
                    if (PL[i].empty() == false)
                    {
                        cout << *PL[i].begin() << "\n";
                        break;
                    }
                }
            }
        }

        else if (op == "recommend3")
        {
            cin >> x >> L;
            int ans = -1;
            if (x == 1)
            {
                for (int i = L; i < 101; ++i)
                {
                    if (PL[i].empty() == false)
                    {
                        ans = *PL[i].begin();
                        break;
                    }
                }
            }
            else
            {
                for (int i = L - 1; i >= 1; --i)
                {
                    if (PL[i].empty() == false)
                    {
                        ans = *(prev(PL[i].end()));
                        break;
                    }
                }
            }
            cout << ans << "\n";
        }

        else if (op == "add")
        {
            cin >> P >> L >> G;
            PN[P] = { L,G };
            PL[L].insert(P);
            PG[G][L].insert(P);
        }

        else if (op == "solved")
        {
            cin >> P;
            PL[PN[P].first].erase(P);
            PG[PN[P].second][PN[P].first].erase(P);
        }
    }

    return 0;
}