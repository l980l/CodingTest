#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	// 이거 사이클 찾는 문제랑 비슷한거 같은데 어케 하더라 흠...
	while (T--)
	{
		int n;
		cin >> n;
		// 학생 번호와 그 학생이 원하는 다른 학생의 번호. 그룹이 지어진 경우 second를 0으로.
		vector<pair<int, int>> Student;		
		Student.push_back({ 0,0 });
		for (int i = 1; i <= n; ++i)
		{
			int a;
			cin >> a;
			// 1인팀인 경우 이미 그룹이 지어졌으니 second를 0으로 넣기.
			if (i == a)
				Student.push_back({ i,0 });
			else
				Student.push_back({ i,a });
		}
		int Result = 0;
		for (int i = 1; i <= n; ++i)
		{
			queue<int> Group;	// 그룹중인 학생 
			Group.push(i);
			auto CurPair = Student[i];
			while (CurPair.second != 0)
			{
				Result++;	// 일단 팀 못 만든다고 생각해.
				int NextIdx = CurPair.second;
				// 다음에 갈 노드가 방문한 노드라면 queue를 비워가면서 그룹이 몇명인지 확인.
				if (Student[NextIdx].second == 0)
				{
					while (!Group.empty())
					{
						// 그룹이 될 때가 언제인지 찾고 남은 그룹 크기만큼 Result에서 뺴줌. 
						if (NextIdx == Group.front())
						{
							Result -= Group.size();
							break;
						}
						Group.pop();
					}
				}
				else
					Group.push(NextIdx);

				Student[CurPair.first].second = 0;	// 방문 처리.
				CurPair = Student[NextIdx];	// 다음 Pair로 바꾸기.
			}
		}
		cout << Result << "\n";
	}

	return 0;
}