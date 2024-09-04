#include <vector>
#include <string>
using namespace std;

int dp[102][102][2];

int solution(vector<string> arr)
{
    int answer = -1;
    for (int i = 0; i <= arr.size() / 2; i++)
    {
        for (int j = i; j <= arr.size() / 2; j++)
        {
            if (i == j)
                dp[i][j][0] = dp[i][j][1] = stoi(arr[i * 2]);
            else
            {
                dp[i][j][0] = -1e9;
                dp[i][j][1] = 1e9;
            }
        }
    }
    for (int k = 1; k <= arr.size() / 2; k++)
    {
        for (int i = 0; i <= arr.size() / 2 - k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (arr[(i + j) * 2 + 1] == "-")
                {
                    dp[i][i + k][0] = max(dp[i][i + k][0], dp[i][i + j][0] - dp[i + j + 1][i + k][1]);
                    dp[i][i + k][1] = min(dp[i][i + k][1], dp[i][i + j][1] - dp[i + j + 1][i + k][0]);
                }
                else
                {
                    dp[i][i + k][0] = max(dp[i][i + k][0], dp[i][i + j][0] + dp[i + j + 1][i + k][0]);
                    dp[i][i + k][1] = min(dp[i][i + k][1], dp[i][i + j][1] + dp[i + j + 1][i + k][1]);
                }
            }
        }
    }
    answer = dp[0][arr.size() / 2][0];
    return answer;
}