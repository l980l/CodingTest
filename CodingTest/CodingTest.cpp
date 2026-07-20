#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    cin >> t;

    for (int tcn = 1; tcn <= t; ++tcn)
    {
        cin >> n;
        vector<int> nums(n);
        vector<int> ops;

        for (int i = 0; i < 4; ++i)
        {
            int temp;
            cin >> temp;
            for (int j = 0; j < temp; ++j)
            {
                ops.push_back(i);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }

        int minS = 0x3f3f3f3f;
        int maxS = -0x3f3f3f3f;
        do
        {
            int curSum = nums[0];
            for (int i = 0; i < n - 1; ++i)
            {
                switch (ops[i])
                {
                case 0:
                    curSum += nums[i + 1];
                    break;
                case 1:
                    curSum -= nums[i + 1];
                    break;
                case 2:
                    curSum *= nums[i + 1];
                    break;
                case 3:
                    curSum /= nums[i + 1];
                    break;
                }
            }

            minS = min(minS, curSum);
            maxS = max(maxS, curSum);
        } while (next_permutation(ops.begin(), ops.end()));

        cout << "#" << tcn << " " << maxS - minS << "\n";
    }

    return 0;
}