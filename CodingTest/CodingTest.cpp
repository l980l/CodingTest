#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int t, n, l;
vector<pair<int, int>> food;
int result;

void func(int sumT, int sumK, int st)
{
    if (sumT > result)
    {
        result = sumT;
    }

    for (int i = st; i < n;++i)
    {
        if (sumK + food[i].Y <= l)
            func(sumT + food[i].X, sumK + food[i].Y, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    for (int tcn = 1;tcn <= t;++tcn)
    {
        cin >> n >> l;
        
        result = 0;
        food.clear();
        
        for (int i = 0;i < n;++i)
        {
            int x, y;
            cin >> x >> y;
            food.push_back({ x,y });
        }

        func(0, 0, 0);

        cout << "#" << tcn << " " << result << "\n";
    }

    return 0;
}