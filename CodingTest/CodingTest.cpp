#include <iostream>
#include <algorithm>

using namespace std;

int unused = 2;
const int mx = 500 * 10000 + 5;
int nxt[mx][26];

int c2i(char c)
{
    return c - 'a';
}

void insert(string& s)
{
    int cur = 1;
    for (auto c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
}

bool find(string& s)
{
    int cur = 1;
    for (auto c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < mx; ++i)
    {
        fill(nxt[i], nxt[i] + 26, -1);
    }

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        insert(temp);
    }

    int result = 0;
    while (M--)
    {
        string temp;
        cin >> temp;
        result += find(temp);
    }

    cout << result;

    return 0;
}