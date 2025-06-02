#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L, A;
    cin >> N >> L;

    vector<int> Result(N);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> PQ;

    for (int i = 0; i < N; ++i)
    {
        cin >> A;
        Result[i] = A;

        PQ.push({ A,i });

        while (!PQ.empty())
        {
            if (PQ.top().second < i - L + 1)
                PQ.pop();
            else
            {
                Result[i] = PQ.top().first;
                break;
            }
        }
    }

    for (int i : Result)
    {
        cout << i << ' ';
    }

    return 0;
}
