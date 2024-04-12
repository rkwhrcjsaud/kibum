#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, P;
int arr[17][17];
int dp[1 << 16];

int bitCount(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}

int solve(int bit)
{
    if (bitCount(bit) >= P)
        return 0;
    int &ret = dp[bit];
    if (ret != -1)
        return ret;
    ret = 1e9;
    for (int i = 0; i < N; i++)
    {
        if (!(bit & (1 << i)))
        {
            for (int j = 0; j < N; j++)
            {
                if (bit & (1 << j))
                    ret = std::min(ret, solve(bit | (1 << i)) + arr[j][i]);
            }
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> arr[i][j];
    std::string str;
    std::cin >> str;
    int bit = 0;
    for (int i = 0; i < N; i++)
        str[i] == 'Y' ? bit |= (1 << i) : 0;
    std::cin >> P;
    std::fill(dp, dp + (1 << 16), -1);
    int ret = solve(bit);
    if (ret == 1e9)
        std::cout << "-1\n";
    else
        std::cout << ret << '\n';
}