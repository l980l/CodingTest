#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> failure(const string& s)
{
    int j = 0;
    vector<int> f((int)s.size());

    for (int i = 1; i < (int)s.size(); ++i)
    {
        while (j > 0 && s[i] != s[j])
            j = f[j - 1];
        if (s[i] == s[j])
            f[i] = ++j;
    }

    return f;
}

bool solve(const vector<int>& f, const string& A, const string& B)
{
    int j = 0; 
    int count = 0;  // 1이어야 함.

    for (int i = 0; i < (int)A.size(); ++i)
    {
        while (j > 0 && A[i] != B[j])
            j = f[j - 1];
        if (A[i] == B[j])
            ++j;
        if (j == B.size())
        {
            count++;
            j = f[j - 1];
        }
    }

    return count == 1;
}

string shift(const string& s, unordered_map<char, int>& AMap, const string& A)
{
    string temp;
    for (char c : s)
    {
        int now = AMap[c];
        now = now + 1 < A.size() ? now + 1 : 0;

        temp.push_back(A[now]);
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    string A, W, S;
    while (tc--)
    {
        vector<int> ans;
        cin >> A >> W >> S;

        unordered_map<char, int> AMap;
        for (int i = 0; i < (int)A.size(); ++i)
        {
            AMap[A[i]] = i;
        }

        vector<int> f = failure(W);

        if (solve(f, S, W) == true)
            ans.push_back(0);

        string sW = W;
        for (int i = 1; i < A.size(); ++i)
        {
            sW = shift(sW, AMap, A);

            if (solve(f, S, sW) == true)
                ans.push_back(i);
        }

        if (ans.size() == 0)
            cout << "no solution" << "\n";
        else if (ans.size() == 1)
            cout << "unique: " << ans.front() << "\n";

        else
        {
            cout << "ambiguous: ";
            for (int i : ans)
            {
                cout << i << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}