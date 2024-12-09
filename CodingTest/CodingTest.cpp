#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    set<int> lm;
    int isLM;
    for (int i = 1; i <= N; ++i)
    {
        cin >> isLM;
        if (isLM == 1)
            lm.insert(i);
    }

    int x, y;
    int idx = 1;
    while (Q--)
    {
        cin >> x;

        if (x == 1)
        {
            cin >> y;

            auto iter = lm.find(y);
            if (iter != lm.end())
                lm.erase(iter);
            else
                lm.insert(y);
        }
        else if (x == 2)
        {
            cin >> y;

            idx = idx + (y % N);
            if (idx > N)
                idx %= N;
        }
        else if (x == 3)
        {
            if (lm.empty() == true)
                cout << -1 << "\n";
            else
            {
                auto iter = lm.lower_bound(idx);
                if (iter == lm.end())
                    cout << *lm.begin() + (N - idx) << "\n";
                else
                    cout << *iter - idx << "\n";
            }
        }
    }

    return 0;
}