#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::string s1, s2, s3;
        std::cin >> s1 >> s2 >> s3;
        std::cout << "Data set " << i << ": ";
        bool dp[201][201] = {false, };
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3)
        {
            std::cout << "no\n";
            continue ;
        }
        dp[0][0] = true;
        for (int i = 1; i <= len1; i++)
        {
            if (s1[i - 1] == s3[i - 1])
                dp[i][0] = true;
            else
                break ;
        }
        for (int i = 1; i <= len2; i++)
        {
            if (s2[i - 1] == s3[i - 1])
                dp[0][i] = true;
            else
                break ;
        }
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s1[i - 1] == s3[i + j - 1])
                    dp[i][j] |= dp[i - 1][j];
                if (s2[j - 1] == s3[i + j - 1])
                    dp[i][j] |= dp[i][j - 1];
            }
        }
        if (dp[len1][len2])
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }
}