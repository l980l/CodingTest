#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, x, y;

    cin >> T;

    while (T--)
    {
        cin >> x >> y;

        x = y - x;

        int result = 0;
        int remain = x;
        int stepNum = 1;
        while (remain > 0)
        {
            remain -= stepNum * 2;
            result += 2;

            if (remain <= 0)
            {
                if (remain + stepNum <= 0)
                    result--;

                break;
            }

            stepNum++;
        }
        
        cout << result << '\n';
    }

    return 0;
}
