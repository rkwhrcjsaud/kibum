#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int N, M, H;
const int MOD = 10007;
std::vector<int> arr[51];
int dp[51][1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> H;
    std::cin.ignore();
    for (int i = 1; i <= N; i++)
    {
        std::string str;
        std::getline(std::cin, str);
        std::stringstream sstr(str);
        int num;
        while (sstr >> num)
            arr[i].push_back(num);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= H; j++)
        {
            for (int k = 0; k < arr[i].size(); k++)
            {
                if (j >= arr[i][k])
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i][k]]) % MOD;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
    }
    std::cout << dp[N][H] << '\n';
}