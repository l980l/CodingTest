#include <iostream>
#include <list>

using namespace std;

void L();
void D();
void B();
void P(char C);

static list<char> Editor;
static list<char>::iterator iter;	// 커서는 이터레이터로 구현하는게 편할듯?

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S;
	cin >> S;
	
	// 음... S의 문자들을 하나하나 list에 넣어주자.
	for (char a : S)
	{
		Editor.push_back(a);
	}

	// 초기 커서는 문장의 맨 뒤에 위치함. 
	iter = Editor.end();

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		char a;
		cin >> a;

		if (a == 'P')
		{
			char b;
			cin >> b;

			P(b);
		}

		else if (a == 'L')
			L();

		else if (a == 'D')
			D();

		else if (a == 'B')
			B();
	}

	for (char a : Editor)
	{
		cout << a;
	}

	return 0;
}

// 커서를 왼쪽으로 이동. 커서가 맨 앞이면 무시.
void L()
{
	if (iter != Editor.begin())
		--iter;
}

// 커서를 오른쪽으로 이동. 커서가 맨 뒤면 무시.
void D()
{
	if (iter != Editor.end())
		++iter;
}

// 커서 왼쪽 문자 삭제. 커서가 맨 앞이면 무시.
void B()
{
	// erase를 하면 자동으로 ++iter가 됨.
	if (iter != Editor.begin())
	{
		// erase를 한 다음 반환되는 iterator로 다시 지정해줘야 잘못된 iter를 가리키지 않음.
		iter = Editor.erase(--iter);
	}
}

// 커서 왼쪽에 문자 추가. 
// 음... 요소를 추가한 다음에는 커서를 옮겨줘야 될거 같은데, insert하면 알아서 ++iter 되네.
// 맨 뒤면 push_back으로 넣어주고 맨 뒤가 아니면 insert로 하면 되겠지? 흠... 맨 뒤에 insert도 되나. 음~ 맨 뒤에도 알아서 잘 insert 해주네~ 
void P(char C)
{
	Editor.insert(iter, C);
}
