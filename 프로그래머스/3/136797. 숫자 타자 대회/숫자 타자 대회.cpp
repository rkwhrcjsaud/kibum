#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dp[12][12][100001];

int toPos(char c)
{
    if (c >= '1' && c <= '9')
        return c - '1';
    else if (c == '0')
        return 10;
    else if (c == '*')
        return 9;
    else
        return 11;
}

int calc(int p, int pos)
{
    if (p == pos)
        return 1;
    int ret = 0;
    int y = abs(p / 3 - pos / 3);
    int x = abs(p % 3 - pos % 3);
    if (x == 0 || y == 0)
        return max(x, y) * 2;
    return min(x, y) * 3 + (max(x, y) - min(x, y)) * 2;
}

int sol(int l, int r, int idx, string &numbers)
{
    if (idx == numbers.size())
        return 0;
    int &ret = dp[l][r][idx];
    if (ret != -1)
        return ret;
    ret = 80000000;
    int pos = toPos(numbers[idx]);
    if (r != pos)
        ret = min(ret, sol(pos, r, idx + 1, numbers) + calc(l, pos));
    if (l != pos)
        ret = min(ret, sol(l, pos, idx + 1, numbers) + calc(r, pos));
    return ret;
}

int solution(string numbers) {
    int answer = 0;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            for (int k = 0; k < numbers.size(); k++)
                dp[i][j][k] = -1;
    answer = sol(3, 5, 0, numbers);
    return answer;
}