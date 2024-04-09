#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N;
int scv[3];
std::vector<int> v;
int dp[61][61][61];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    v.push_back(1);
    v.push_back(3);
    v.push_back(9);
    for (int i = 0; i < N; i++)
        std::cin >> scv[i];
    for (int i = 0; i <= scv[0]; i++)
    {
        for (int j = 0; j <= scv[1]; j++)
        {
            for (int k = 0; k <= scv[2]; k++)
            {
                if (i == 0 && j == 0 && k == 0)
                    continue;
                dp[i][j][k] = 1000000000;
                std::vector<int> tmp = v;
                do
                {
                    dp[i][j][k] = std::min(dp[i][j][k], dp[std::max(0, i - tmp[0])][std::max(0, j - tmp[1])][std::max(0, k - tmp[2])] + 1);
                } while (std::next_permutation(tmp.begin(), tmp.end()));
            }
        }
    }
    std::cout << dp[scv[0]][scv[1]][scv[2]] << '\n';
}