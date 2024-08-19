#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long M;
    cin >> N >> M;

    vector<int> Num;
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        Num.push_back(temp);
    }

    long long sum = Num[0];
    int st = 0;
    int en = 1;
    int result = 0;

    while (true)
    {
        if (sum == M)
            result++;
        if (sum <= M)
        {
            if (en < int(Num.size()))
                sum += Num[en++];
        }
        if (sum > M)
            sum -= Num[st++];
        if (en >= int(Num.size()))
        {
            if (sum == M)
                result++;
            break;
        }
    }

    if (N == 1)
    {
        if (Num[0] == M)
            result = 1;
        else
            result = 0;
    }

    cout << result;

    return 0;
}