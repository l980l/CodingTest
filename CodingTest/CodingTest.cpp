#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, d, c;
    cin >> N;

    // 초기 정렬에는 pq가 아니라 vector에 넣고 sort 하는게 나을 거 같기도
    vector<priority_queue<int, vector<int>>> vecPQ(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        cin >> d >> c;
        vecPQ[d].push(c);
    }

    priority_queue<int, vector<int>, greater<int>> resultPQ;
    long long result = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (vecPQ[i].empty() == true)
            continue;

        resultPQ.push(vecPQ[i].top());
        result += vecPQ[i].top();
        vecPQ[i].pop();

        while (true)
        {
            if (resultPQ.size() < i && vecPQ[i].empty() == false)
            {
                resultPQ.push(vecPQ[i].top());
                result += vecPQ[i].top();
                vecPQ[i].pop();
            }

            else if (resultPQ.empty() == false && vecPQ[i].empty() == false && resultPQ.top() < vecPQ[i].top())
            {
                result -= resultPQ.top();
                resultPQ.pop();
                resultPQ.push(vecPQ[i].top());
                result += vecPQ[i].top();
                vecPQ[i].pop();
            }

            else
                break;
        }
    }

    cout << result;

    return 0;
}