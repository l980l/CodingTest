#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tcn = 1;tcn <= t;++tcn)
    {
        p.clear();
        string temp;
        cin >> temp;

        int result = 0;
        int sum = temp[0] - '0';
        for (int i = 1; i < temp.size();++i)
        {
            int cur = temp[i] - '0';

            if (cur > 0 && i > sum)
            {
                result += i - sum;
                sum += i - sum;
            }

            sum += cur;
        }

        cout << "#" << tcn << " " << result << "\n";
    }

    return 0;
}

