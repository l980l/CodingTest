#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    unordered_map<string, int> clothes;
    string temp, temp2;

    while (t--)
    {
        cin >> n;
        clothes.clear();

        if (n == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        while (n--)
        {
            cin >> temp >> temp2;
            ++clothes[temp2];
        }

        int result = 0;
        for (auto c : clothes)
        {
            if (result == 0)
                result = c.second + 1;
            else
                result *= c.second + 1;
        }
        cout << result - 1 << "\n";
    }

    return 0;
}