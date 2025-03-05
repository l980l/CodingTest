#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> lc;
vector<int> rc;
int N, colno, root;

vector<pair<int, int>> colLR;
void inorder(int curr, int d) 
{
    if (curr == -1) 
        return;

    inorder(lc[curr], d + 1);
    colno++;

    int& lcol = colLR[d].first;
    int& rcol = colLR[d].second;

    if (!lcol || colno < lcol) 
        lcol = colno;
    if (!rcol || rcol < colno) 
        rcol = colno;

    inorder(rc[curr], d + 1);
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    lc = vector<int>(N + 1);
    rc = vector<int>(N + 1);
    colLR = vector<pair<int, int>>(N + 1);
    vector<bool> isRoot(N + 1, true);

    for (int i = 0; i < N; i++) 
    {
        int p, l, r;
        cin >> p >> l >> r;
        lc[p] = l;
        rc[p] = r;

        if (l != -1) 
            isRoot[l] = false;

        if (r != -1) 
            isRoot[r] = false;
    }

    for (int i = 1; i <= N; i++)
    {
        if (isRoot[i])
        {
            root = i;
            break;
        }
    }

    int mxWidth = 0, mxDepth = 0;
    inorder(root, 0);

    for (int d = 0; d < N; d++) 
    {
        int lcol = colLR[d].first;
        int rcol = colLR[d].second;

        if (lcol + rcol == 0) 
            break;

        int width = rcol - lcol + 1;

        if (mxWidth < width) 
        {
            mxWidth = width;
            mxDepth = d;
        }
    }
    cout << mxDepth + 1 << ' ' << mxWidth;
}