#include <vector>
#include <string.h>

using namespace std;

int MOD = 20170805;
int dp[501][501][2];
int M, N;
int sol(int y, int x, int prev, vector<vector<int>> &city_map)
{
    if (y == M - 1 && x == N - 1)
        return 1;
    int &ret = dp[y][x][prev];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < 2; i++)
    {
        int ny = y + i % 2;
        int nx = x + (i + 1) % 2;
        if (ny >= M || nx >= N)
            continue ;
        if (city_map[ny][nx] == 1)
            continue ;
        if (city_map[y][x] == 2 && prev == ((i + 1) % 2))
            continue ;
        ret += sol(ny, nx, i % 2, city_map);
        ret %= MOD;
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    M = m, N = n;
    int answer = 0;
    memset(dp, -1, sizeof(dp));
    answer = sol(0, 0, 0, city_map);
    return answer;
}