#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;

    int n, x;
    cin >> n;

    for (int i = 0; i < n * n; ++i)
    {
        cin >> x;
        pq.push(x);

        if ((int)pq.size() > n)
            pq.pop();
    }
    
    cout << pq.top();

    return 0;
}