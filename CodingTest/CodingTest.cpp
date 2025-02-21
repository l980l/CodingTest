#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;

    int N, x;
    cin >> N;

    while (N--)
    {
        cin >> x;

        if (x == 0)
        {
            if (pq.empty() == true)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }

        else
        {
            pq.push(x);
        }
    }

    return 0;
}