#include <string>
#include <vector>
#include <iostream>

using namespace std;
int N;
int l[1000002];
int r[1000002];

int solution(vector<int> a) {
    int answer = min(2, (int)a.size());
    N = a.size();
    l[0] = a[0];
    for (int i = 1; i < N; i++)
        l[i] = min(l[i - 1], a[i]);
    r[N - 1] = a[N - 1];
    for (int i = N - 2; i >= 0; i--)
        r[i] = min(r[i + 1], a[i]);
    // i = 0, N - 1 인 경우는 무조건 살아남을 수 있음
    for (int i = 1; i < N - 1; i++)
    {
        // 작은 풍선을 터트린 적이 없는 방향에서 a[i]보다 큰 수가 존재한다면 살아남음
        if (l[i - 1] > a[i] || r[i + 1] > a[i])
            answer++;
    }
    return answer;
}