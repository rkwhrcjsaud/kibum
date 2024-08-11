#include <string>
#include <vector>

using namespace std;

int n;
int t;
int lt, ut;
int aa, bb;
vector<int> board;
int dp[1001][2051];

int sol(int idx, int cur)
{
    if (idx == n)
        return 0;
    if (board[idx] && (cur > ut || cur < lt))
        return 500000;
    int &ret = dp[idx][cur];
    if (ret != -1)
        return ret;
    ret = 500000;
    // 온도를 올리고 싶은 경우
    if (t > cur) // 에어컨이 꺼져있을 때
        ret = min(ret, sol(idx + 1, cur + 1));
    else // 에어컨이 켜져있을 때
        ret = min(ret, sol(idx + 1, cur + 1) + aa);
    // 온도를 유지하고 싶은 경우
    if (t == cur) // 에어컨이 꺼져있을 때
        ret = min(ret, sol(idx + 1, cur));
    else // 에어컨이 켜져있을 때
        ret = min(ret, sol(idx + 1, cur) + bb);
    // 온도를 내리고 싶은 경우
    if (t < cur)
        ret = min(ret, sol(idx + 1, cur - 1));
    else
        ret = min(ret, sol(idx + 1, cur - 1) + aa);
    return ret;
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    n = onboard.size();
    t = temperature + 1010;
    lt = t1 + 1010;
    ut = t2 + 1010;
    aa = a;
    bb = b;
    board = onboard;
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 2051; j++)
            dp[i][j] = -1;
    int answer = sol(0, t);
    return answer;
}