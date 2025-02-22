#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 작은 값들을 모아둔 최대힙 pq와 큰 값들을 모아둔 최소힙 pq로 해보자
    priority_queue<int, vector<int>> sg;
    priority_queue<int, vector<int>, greater<int>> lg;

    int N, x;
    cin >> N;

    cin >> x;
    sg.push(x);
    cout << sg.top() << "\n";

    for (int i = 1; i < N; ++i)
    {
        cin >> x;

        if (lg.empty() == false && lg.top() <= x)
        {
            lg.push(x);
        }
        else
        {
            sg.push(x);
        }

        if (sg.size() - lg.size() == -1)
        {
            sg.push(lg.top());
            lg.pop();
        }

        else if (sg.size() - lg.size() == 2)
        {
            lg.push(sg.top());
            sg.pop();
        }

        cout << sg.top() << "\n";
    }

    return 0;
}