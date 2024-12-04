#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long N, P, Q;

void func(long long n, unordered_set<long long>& set)
{
    if (n == 0)
        return;

    set.insert(n);
    func(n / P, set);
    func(n / Q, set);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> Q;

    unordered_map<long long, long long> DP;
    DP[0] = 1;

    vector<long long> idxList;
    {
        unordered_set<long long> idxSet;
        func(N, idxSet);
        idxList = vector(idxSet.begin(), idxSet.end());
    }

    sort(idxList.begin(), idxList.end());

    auto iter = idxList.begin();

    for (long long i : idxList)
    {
        DP[i] = DP[i / P] + DP[i / Q];
    }

    cout << DP[N];

    return 0;
}