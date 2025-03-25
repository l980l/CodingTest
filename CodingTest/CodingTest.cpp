#include <iostream>

using namespace std;

int unused = 2;
const int mx = 10 * 10000 + 5;
bool chk[mx];
int nxt[mx][10];

int c2i(char c)
{
    return c - '0';
}

bool insert(string& s)
{
    int cur = 1;
    bool ans = false;

    for (auto c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
        {
            nxt[cur][c2i(c)] = unused++;
            ans = true;
        }

        cur = nxt[cur][c2i(c)];

        if (chk[cur] == true)
            break;
    }

    chk[cur] = true;
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unused = 2;
        for (int i = 0; i < mx; ++i)
        {
            chk[i] = false;
            fill(nxt[i], nxt[i] + 10, -1);
        }

        bool result = true;
        while (n--)
        {
            string temp;
            cin >> temp;

            if (insert(temp) == false)
            {
                result = false;
            }
        }

        string temp = result ? "YES" : "NO";
        cout << temp << '\n';
    }

    return 0;
}