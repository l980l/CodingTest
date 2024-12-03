#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> sites;

    for (int i = 0; i < N; ++i)
    {
        string temp, temp2;
        cin >> temp >> temp2;

        sites[temp] = temp2;
    }

    for (int i = 0; i < M; ++i)
    {
        string temp;
        cin >> temp;

        cout << sites[temp] << "\n";
    }

    return 0;
}