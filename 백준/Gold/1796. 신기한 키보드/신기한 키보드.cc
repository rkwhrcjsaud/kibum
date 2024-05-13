#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

std::string str;
int size;
int arr[27][3];
// j = 0 일 때, i번째 문자가 첫번째로 등장하는 idx
// j = 1 일 때, i번째 문자가 마지막으로 등장하는 idx
// j = 2 일 때, i번째 문자가 등장하는 횟수
int dp[27][51];

int solve(int alpha, int idx)
{
    if (alpha == 26)
        return 0;
    int &ret = dp[alpha][idx];
    if (ret != 1e9)
        return ret;
    ret = 1e9;
    if (arr[alpha][2] == 0)
        return ret = solve(alpha + 1, idx);
    // alpha번째 문자를 오른쪽부터 왼쪽으로 탐색할 때
    int plus = std::abs(arr[alpha][1] - idx) + (arr[alpha][1] - arr[alpha][0]) + arr[alpha][2];
    ret = std::min(ret, solve(alpha + 1, arr[alpha][0]) + plus);
    // alpha번째 문자를 왼쪽부터 오른쪽으로 탐색할 때
    plus = std::abs(arr[alpha][0] - idx) + (arr[alpha][1] - arr[alpha][0]) + arr[alpha][2];
    ret = std::min(ret, solve(alpha + 1, arr[alpha][1]) + plus);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    size = str.size();
    memset(arr, -1, sizeof(arr));
    for (int i = 0; i < 26; i++)
    {
        arr[i][2] = 0;
        for (int j = 0; j < size; j++)
        {
            dp[i][j] = 1e9;
            if (str[j] - 'a' == i)
            {
                if (arr[i][0] == -1)
                    arr[i][0] = j;
                arr[i][1] = j;
                arr[i][2]++;
            }
        }
    }
    std::cout << solve(0, 0) << '\n';
}
