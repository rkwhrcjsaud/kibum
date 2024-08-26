#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;
int dp[501][501];
int H;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    H = triangle.size();
    for (int i = 0; i < H; i++)
        dp[H - 1][i] = triangle[H - 1][i];
    for (int i = H - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[i][j] = triangle[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
    return answer = dp[0][0];
}