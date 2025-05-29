#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c, x;
vector<int> h;

bool func(int step)
{
    int idx = 0;
    int count = 0;
    
    while (idx < n)
    {
        idx = lower_bound(h.begin() + idx, h.end(), (h.front() + step)) - h.begin();
        ++count;
    }

    return count >= c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        h.push_back(x);
    }

    sort(h.begin(), h.end());

    int st = 0;
    int en = h.back();

    while (st < en)
    {
        int mid = (st + en + 1) / 2;

        if (func(mid))
            st = mid;
        else
            en = mid - 1;
    }

    cout << st;

    return 0;
}
