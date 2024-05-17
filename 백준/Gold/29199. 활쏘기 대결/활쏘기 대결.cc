#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

int N;
int point[200002];
long long psum[200002];
long long dp[200002];

/*
두 플레이어가 번갈아 가며 차례를 가지고 게임을 진행한다.
각 플레이어는 자신의 차례에 아래 두 가지 동작 중 하나를 선택한다.
1. 표적 하나를 선택하고 그 표적을 맞힌다. 이 경우 자신의 점수가 표적의 점수만큼 증가한다.
2. 기권한다. 이 경우 남은 표적의 점수의 합이 상대의 점수에 더해진다.
또한 표적을 맞추면 그 표적보다 idx가 큰 표적들 중 파괴되지 않은 표적들의 점수를 상대방에게 더해준다.
두 플레이어 모두 자신의 점수를 최대화하려고 할 때, 먼저 시작하는 플레이어의 최대 점수를 출력하라.
*/

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> point[i];
        psum[i] = psum[i - 1] + point[i];
    }
    for (int i = 0; i <= N; i++)
        dp[i] = -1e18;
    dp[1] = point[1] > 0 ? point[1] : 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = std::max(dp[i - 1], psum[i] - dp[i - 1]);
    }
    std::cout << dp[N] << '\n';
}