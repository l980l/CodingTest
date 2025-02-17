#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    int N;
    long long x;
    cin >> N;

    while (N--)
    {
        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << pq.top().first * pq.top().second << "\n";
                pq.pop();
            }
        }

        else
        {
            pair<int, int> temp;
            if (x > 0)
            {
                temp.first = x;
                temp.second = 1;
            }
            else
            {
                temp.first = -x;
                temp.second = -1;
            }
            pq.push(temp);
        }
    }

    return 0;
}