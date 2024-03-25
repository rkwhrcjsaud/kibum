#include <iostream>
#include <vector>

int N, M, C;
std::vector<int> v;
int dp[1 << 14][11][21];

int solution(int jewel, int idx, int capa)
{
    if (jewel == (1 << N) - 1 || idx == M)
        return 0;
    int &ret = dp[jewel][idx][capa];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < N; i++)
    {
        if (jewel & (1 << i) || capa < v[i])
            continue ;
        if (capa - v[i] > 0)
            ret = std::max(ret, solution(jewel | (1 << i), idx, capa - v[i]) + 1);
        ret = std::max(ret, solution(jewel | (1 << i), idx + 1, C) + 1);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> C;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    std::fill(&dp[0][0][0], &dp[0][0][0] + (1 << 14) * 11 * 21, -1);
    std::cout << solution(0, 0, C) << '\n';
}