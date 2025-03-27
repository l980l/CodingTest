#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

vector<string> board;
int wordCount = 0;
int score = 0;
string mxWord;

int unused = 2;
const int mx = 300000 * 8 + 5;
int chk[mx];
int nxt[mx][26];

int c2i(char c)
{
    return c - 'A';
}

void insert(string& s)
{
    int cur = 1;

    for (char c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }

    ++chk[cur];
}

bool find(string& s)
{
    int cur = 1;
    string temp;

    for (char c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
        temp.push_back(c);

        if (chk[cur] == 1)
        {
            ++wordCount;
            if (temp.size() > 2 && temp.size() <= 4)
                score += 1;
            else if (temp.size() == 5)
                score += 2;
            else if (temp.size() == 6)
                score += 3;
            else if (temp.size() == 7)
                score += 5;
            else if (temp.size() == 8)
                score += 11;

            // 사전순 비교가 이게 되나 모르겠네
            if ((mxWord.size() < temp.size()) || ((mxWord.size() == temp.size()) && (mxWord > temp)))
                mxWord = temp;

            ++chk[cur];
        }
    }

    return true;
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

    int w;
    cin >> w;
    while (w--)
    {
        string temp;
        cin >> temp;
        insert(temp);
    }

    int b;
    cin >> b;

    queue<tuple<int, int, string, vector<vector<bool>>>> q;
    while (b--)
    {
        for (int i = 0; i < mx; ++i)
        {
            if(chk[i] > 0)
                chk[i] = 1;
        }

        board.clear();
        wordCount = 0;
        score = 0;
        mxWord.clear();
        unused = 2;

        for (int i = 0; i < 4; ++i)
        {
            string temp;
            cin >> temp;
            board.push_back(temp);
        }

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                vector<vector<bool>> visit(4, vector<bool>(4, false));
                string word;
                word.push_back(board[i][j]);
                
                if (find(word) == false)
                    continue;

                visit[i][j] = true;
                q.push({i, j, word, visit});

                while (!q.empty())
                {
                    int cx, cy;
                    string w;
                    vector<vector<bool>> v;
                    tie(cx, cy, w, v) = q.front();
                    q.pop();

                    for (int i = 0; i < 8; ++i)
                    {
                        int nx = cx + dx[i];
                        int ny = cy + dy[i];

                        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
                            continue;
                        if (v[nx][ny] == true)
                            continue;

                        string nw = w;
                        nw.push_back(board[nx][ny]);
                        
                        if (find(nw) == true)
                        {
                            v[nx][ny] = true;
                            q.push({ nx,ny,nw,v });
                            v[nx][ny] = false;
                        }
                    }
                }
            }
        }

        cout << score << ' ';
        cout << mxWord << ' ';
        cout << wordCount << '\n';
    }

    return 0;
}