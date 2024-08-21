#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> Sushi(N);
    vector<int> visit(d + 1);

    for (int i = 0; i < N; ++i)
    {
        cin >> Sushi[i];
    }

    // 초기 세팅
    visit[c]++;
    int count = 1;
    int result = 0;
    for (int i = 0; i < k; ++i)
    {
        if(visit[Sushi[i]] == 0)
            count++;

        visit[Sushi[i]]++;
    }
    result = max(result, count);

    int en = k;
    for (int st = 1; st < N; ++st)
    {
        if (--visit[Sushi[st - 1]] == 0)
            count--;
        if (visit[Sushi[en]] == 0)
            count++;
        visit[Sushi[en]]++;

        result = max(result, count);

        en++;
        if (en == N)
            en = 0;
    }

    cout << result;

    return 0;
}