#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> Nums(N, -1);
    stack<pair<int, int>> Stack;

    int A;
    for (int i = 0; i < N; ++i)
    {
        cin >> A;

        while (!Stack.empty())
        {
            if (Stack.top().first < A)
            {
                auto pair = Stack.top();
                Stack.pop();

                Nums[pair.second] = A;
            }

            else
                break;
        }

        Stack.push({ A, i });
    }

    for (int i : Nums)
    {
        cout << i << ' ';
    }

    return 0;
}
