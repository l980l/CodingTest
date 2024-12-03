#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> dictionary1;
    unordered_map<int, string> dictionary2;
    for (int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        dictionary1[temp] = i + 1;
        dictionary2[i + 1] = temp;
    }

    for (int i = 0; i < M; ++i)
    {
        string temp;
        cin >> temp;

        auto findResult = dictionary1.find(temp);
        if (findResult != dictionary1.end())
            cout << (*findResult).second << "\n";

        else
        {
            int tempInt = stoi(temp);
            auto result = dictionary2.find(tempInt);
            cout << (*result).second << "\n";
        }
    }

    return 0;
}