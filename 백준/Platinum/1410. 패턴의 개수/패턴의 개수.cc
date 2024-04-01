#include <iostream>
#include <vector>
#include <bitset>

const int mod = 1000003;
int N, K;
int ans, len;
int dp[50][1 << 15];
std::vector < std::string > v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        v.push_back(str);
    }
    len = v[0].size();
    for (int i = 0; i < len; ++i)
    {
        for (char c = 'a'; c <= 'z'; ++c)
        {
            int bit = 0;
            for (int j = 0; j < N; ++j)
            {
                if (v[j][i] == c || v[j][i] == '?')
                    bit |= (1 << j);
            }
            if (!i)
                dp[i][bit]++;
            else
            {
                for (int j = 0; j < (1 << N); ++j)
                    dp[i][j & bit] = (dp[i][j & bit] + dp[i - 1][j]) % mod;
            }
        }
    }
    for (int i = 0; i < (1 << N); ++i)
    {
        std::bitset<15> bit(i);
        if (bit.count() == K)
            ans = (ans + dp[len - 1][i]) % mod;
    }
    std::cout << ans << '\n';
}