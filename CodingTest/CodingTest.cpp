#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    multiset<pair<int, int>> J;
    for (int i = 0; i < N; ++i)
    {
        int M, V;
        cin >> M >> V;

        J.insert(make_pair(V, M));
    }

    multiset<int> Bag;
    for(int i =0;i<K;++i)
    {
        int c;
        cin >> c;
        Bag.insert(c);
    }

    long long result = 0;
    
    auto iter = prev(J.end());
    for (; iter != J.begin(); --iter)
    {
        if (Bag.empty() == true)
            break;

        auto bagIter = Bag.lower_bound((*iter).second);
        if (bagIter != Bag.end())
        {
            result += (*iter).first;
            Bag.erase(bagIter);
        }
    }

    iter = J.begin();
    auto bagIter = Bag.lower_bound((*iter).second);
    if (bagIter != Bag.end())
    {
        result += (*iter).first;
        Bag.erase(bagIter);
    }

    cout << result;

    return 0;
}