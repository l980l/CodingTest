#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, L;
    cin >> K >> L;

    unordered_map<string, int> queue;

    for (int i = 0; i < L; ++i)
    {
        string temp;
        cin >> temp;

        queue[temp] = i;
    }

    vector<pair<int, string>> vec;
    for (auto student : queue)
    {
        vec.push_back(make_pair(student.second, student.first));
    }
    sort(vec.begin(), vec.end());

    int last = min((int)vec.size(), K);
    for (int i = 0; i < last; ++i)
    {
        cout << vec[i].second << "\n";
    }

    return 0;
}