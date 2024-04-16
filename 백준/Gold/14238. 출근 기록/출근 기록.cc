#include <iostream>

std::string str;
std::string ans;
int len;

int arr[3];
int dp[51][51][51][3][3];

bool solve(int a, int b, int c, int prev, int prev2)
{
    if (a + b + c == len)
    {
        if (a == arr[0] && b == arr[1] && c == arr[2])
        {
            std::cout << ans << '\n';
            exit(0);
        }
    }
    if (dp[a][b][c][prev][prev2])
        return false;
    dp[a][b][c][prev][prev2] = 1;
    if (a < arr[0])
    {
        ans[a + b + c] = 'A';
        if (solve(a + 1, b, c, 0, prev))
            return true;
    }
    if (b < arr[1] && prev != 1)
    {
        ans[a + b + c] = 'B';
        if (solve(a, b + 1, c, 1, prev))
            return true;
    }
    if (c < arr[2] && prev != 2 && prev2 != 2)
    {
        ans[a + b + c] = 'C';
        if (solve(a, b, c + 1, 2, prev))
            return true;
    }
    return false;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    len = str.length();
    ans.resize(len);
    for (int i = 0; i < len; i++)
        arr[str[i] - 'A']++;
    if (solve(0, 0, 0, 0, 0))
        return 0;
    std::cout << "-1\n";
}