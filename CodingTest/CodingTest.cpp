#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, a, b, p;
    cin >> t;

    for (int tcn = 1; tcn <= t; ++tcn)
    {
        cin >> n;

        vector<int> st;
        vector<int> en;
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            st.push_back(temp);

            cin >> temp;
            en.push_back(temp);
        }

        cin >> p;
        vector<int> c(p + 1);
        vector<int> result(p + 1, n);
        for (int i = 1; i <= p; ++i)
        {
            cin >> c[i];
        }

        for (int i : st)
        {
            for (int j = 1; j <= p; ++j)
            {
                if (i > c[j])
                    --result[j];
            }
        }
        for (int i : en)
        {
            for (int j = 1; j <= p; ++j)
            {
                if (i < c[j])
                    --result[j];
            }
        }

        cout << "#" << tcn;
        for (int i = 1; i <= p; ++i)
        {
            cout << " " << result[i];
        }
        cout << "\n";
    }

    return 0;
}

