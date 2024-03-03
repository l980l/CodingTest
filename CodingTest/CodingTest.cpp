#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

bool mask[25];
string board[5];	
int ans;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; ++i)
	{
		cin >> board[i];
	}

	// 25명 중 칠공주가 될 사람의 후보 조합을 뽑는다.
	fill(mask + 7, mask + 25, true);
	// 모든 조합에 BFS를 돌려버리는거야
	do
	{
		queue<pair<int, int>> q;
		// 구성원 중에서 이다솜파의 수, 가로 세로로 인접한 사람의 수
		int dasom = 0, adj = 0;
		// 이번 조합에서 7공주로 뽑혔는지, 방문 배열
		bool bPrincess7[5][5] = {}, vis[5][5] = {};
		// 모든 학생 체크.
		for (int i = 0; i < 25; ++i)
		{
			// mask[i]가 0인 경우, 7공주로 선택된 아이인 것임. q에 넣고, 방문 여부도 true로 해줌. 모든 공주를 queue에 넣고 시작하는 것.
			if (!mask[i])
			{
				int x = i / 5, y = i % 5;
				bPrincess7[x][y] = true;
				if (q.empty())
				{
					q.push({ x,y });
					vis[x][y] = true;
				}
			}
		}
		// 이제 공주 하나하나에서 BFS를 돌기 시작함. 이번에 선택된 공주들이 서로 붙어 있는지, 붙어 있다면 다솜 파가 4명 이상인지를 확인하는 거임.
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front(); // tuple 인클루드 해야 tie 사용 가능.
			
			q.pop();
			// 붙어있는 아이 수 ++ 
			adj++;
			// S인 경우에만 1을 더하는 코드를 이렇게 작성할 수 있구나.
			dasom += board[x][y] == 'S';
			for (int k = 0; k < 4; ++k)
			{
				int nx = x + dx[k], ny = y + dy[k];
				// 붙어있는 아이를 확인했는데 방문한 적 있거나, 이번에 선택된 공주가 아닌 경우 continue.
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !bPrincess7[nx][ny])
					continue;
				q.push({ nx,ny });
				vis[nx][ny] = true;
			}

			// 인접한 학생 수까지 합쳐서 7 이상이면, 이번 7공주가 붙어있다는 것이다. 이때, 다솜파가 4이상이면 ans++ 이 되도록
			ans += (adj >= 7 && dasom >= 4);
		}
	} while (next_permutation(mask, mask + 25)); // mask는 bool 배열이기 때문에 next permutation으로 모든 조합을 체크. algorithm include 해야함.

	cout << ans;

	return 0;
}