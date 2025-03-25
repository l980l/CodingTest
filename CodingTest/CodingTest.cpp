#include <iostream>
#include <algorithm>

using namespace std;

int unused = 2;
const int mx = 100000 * 10 + 5;
int chk[mx];
int nxt[mx][26];

int c2i(char c)
{
    return c - 'a';
}

string insert(string& s)
{
    int cur = 1;
    bool isPrefix = true;

    string ans;
    for (auto c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
        {
            if (isPrefix == true)
            {
                isPrefix = false;
                ans.push_back(c);
            }
            nxt[cur][c2i(c)] = unused++;
        }
        else
            ans.push_back(c);
        
        cur = nxt[cur][c2i(c)];
    }
    ++chk[cur];

    if (ans == s)
    {
        if (chk[cur] != 1)
        {
            int ori = chk[cur];
            string temp;
            while (ori > 0)
            {
                temp.push_back(ori % 10 + '0');
                ori /= 10;
            }
            reverse(temp.begin(), temp.end());
            ans.append(temp);
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < mx; ++i)
    {
        chk[i] = 0;
        fill(nxt[i], nxt[i] + 26, -1);
    }

    int N;
    cin >> N;
    while (N--)
    {
        string temp;
        cin >> temp;

        cout << insert(temp) << '\n';
    }

    return 0;
}