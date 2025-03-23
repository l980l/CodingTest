#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> failure(string s)
{
    vector<int> f((int)s.size());
    int j = 0;
    for (int i = 1; i < (int)s.size(); ++i)
    {
        while (j > 0 && s[i] != s[j])
            j = f[j - 1];
        if (s[i] == s[j])
            f[i] = ++j;
    }

    return f;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string T, P;

    getline(cin, T);
    getline(cin, P);

    vector<int> f = failure(P);
    vector<int> F(T.size());      // T와 P로 만든 실패함수 느낌

    int j = 0;
    for (int i = 0; i < (int)T.size(); ++i)
    {
        while (j > 0 && T[i] != P[j])
            j = f[j - 1];
        if (T[i] == P[j])
            F[i] = ++j;
        
        if (j == P.size())
            j = f[j - 1];
    }

    int count = 0;
    vector<int> index;
    for (int i = 0; i < (int)F.size(); ++i)
    {
        if (F[i] == P.size())
        {
            ++count;
            index.push_back(i - P.size() + 2);     // 문자의 끝 주소이기 때문에 (크기 - 1)만큼 빼준다. 또한 문제에서 원하는 것은 1-indexed이기 때문에 + 1을 한번 더 해준다.
        }
    }

    cout << count << '\n';
    for (int i : index)
    {
        cout << i << ' ';   
    }

    return 0;
}