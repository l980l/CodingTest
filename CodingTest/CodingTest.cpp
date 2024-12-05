#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int k;
        cin >> k;

        set<int> Q;
        while (k--)
        {
            char Op;
            int Num;
            cin >> Op >> Num;

            if (Op == 'I')
                Q.insert(Num);

            else
            {
                if (Num == 1)
                {
                    if (Q.empty() == false)
                        Q.erase(prev(Q.end()));
                }

                else
                {
                    if (Q.empty() == false)
                        Q.erase(Q.begin());
                }
            }
        }

        if (Q.empty() == true)
        {
            cout << "EMPTY" << "\n";
            continue;
        }

        else
            cout << *prev(Q.end()) << " " << *Q.begin() << "\n";
    }


    return 0;
}