#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, P, L;
    cin >> N;
    vector<set<int>> prob(101);
    for (int i = 0; i < N; ++i)
    {
        cin >> P >> L;
        prob[L].insert(P);
    }

    int M;
    cin >> M;
    string opr;

    while (M--)
    {
        cin >> opr;
        
        if (opr == "recommend")
        {
            cin >> P;
            if (P == 1)
            {
                for (int i = 100; i > 0; --i)
                {
                    if (prob[i].empty() == false)
                    {
                        cout << *prev(prob[i].end()) << "\n";
                        break;
                    }
                }
            }
            else
            {
                for (int i = 1; i < 101; ++i)
                {
                    if (prob[i].empty() == false)
                    {
                        cout << *prob[i].begin() << "\n";
                        break;
                    }
                }
            }
        }
        else if (opr == "add")
        {
            cin >> P >> L;

            prob[L].insert(P);
        }
        else if (opr == "solved")
        {
            cin >> P;
            for (int j = 1; j < 101; ++j)
            {
                if (prob[j].find(P) != prob[j].end())
                {
                    prob[j].erase(prob[j].find(P));
                    break;
                }
            }
        }
    }

    return 0;
}