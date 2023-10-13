#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>>		Tree;
static vector<pair<int, int>>	DepthAndParent;
static queue<int>				Queue;
static vector<bool>				Visit;

void CalculateDepthAndParent();
int FindResult(int IndexA, int IndexB);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	Tree.resize(N + 1);
	DepthAndParent.resize(N + 1);
	Visit = vector<bool>(N + 1, false);

	for (int i = 1; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;

		// 방향이 없기 때문에 양쪽에 저장.
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	// DepthAndParent 구하기
	CalculateDepthAndParent();

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << FindResult(a, b) << '\n';
	}

	return 0;
}

void CalculateDepthAndParent()
{
	// BFS를 이용해서 Depth와 Parent 구하기.
	// 루트 노드 Queue에 추가
	Queue.push(1);
	Visit[1] = true;

	int Count = 0;	// 현재 Depth에서 몇 개의 노드를 처리 했는지를 의미.
	int Breadth = 1;	// 현재 레벨의 노드 개수.
	int Depth = 1;

	while (!Queue.empty())
	{
		// 현재 노드 인덱스.
		int Index = Queue.front();
		Queue.pop();

		// Tree[Index]의 자식 노드들을 Queue에 넣어주기.
		for (int i : Tree[Index])
		{
			// 미방문 노드만. 방문 처리를 해주고, 깊이와 부모 노드 기록.
			if (!Visit[i])
			{
				Visit[i] = true;
				Queue.push(i);
				DepthAndParent[i] = make_pair(Depth, Index);
			}
		}

		// 처리한 노드 수 + 1
		++Count;

		if (Count == Breadth)
		{
			Count = 0;
			// 현재 레벨은 처리한 상태이기 때문에 Queue에는 다음 레벨의 노드만 남아있게 된다. 따라서 Breadth를 다음 레벨의 것으로 업데이트 하려면 단순히 Queue의 Size를 넣어주면 된다. 
			Breadth = Queue.size();
			++Depth;
		}
	}
}

int FindResult(int IndexA, int IndexB)
{
	int LeftNodeIdx = IndexA;
	int RightNodeIdx = IndexB;

	// 무조건 LeftNode가 더 깊거나 같은 레벨이도록 처리
	if (DepthAndParent[LeftNodeIdx].first < DepthAndParent[RightNodeIdx].first)
		swap(LeftNodeIdx, RightNodeIdx);

	// 깊이가 같아질 때까지 반복. 
	while (DepthAndParent[LeftNodeIdx].first != DepthAndParent[RightNodeIdx].first)
	{
		// LeftNodeIdx를 부모 노드로.
		LeftNodeIdx = DepthAndParent[LeftNodeIdx].second;
	}

	// 같은 노드가 나올 때까지 반복.
	while (LeftNodeIdx != RightNodeIdx)
	{
		LeftNodeIdx = DepthAndParent[LeftNodeIdx].second;
		RightNodeIdx = DepthAndParent[RightNodeIdx].second;
	}

	return LeftNodeIdx;
}
