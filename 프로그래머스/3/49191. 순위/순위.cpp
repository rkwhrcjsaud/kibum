#include <string>
#include <vector>
#include <iostream>

using namespace std;
int winToLose[101][101];
int loseToWin[101][101];
const int INF = 1e9;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            loseToWin[i][j] = INF;
            winToLose[i][j] = INF;
        }
    }
    for (int i = 0; i < results.size(); i++)
    {
        int winner = results[i][0];
        int loser = results[i][1];
        loseToWin[loser][winner] = 1;
        winToLose[winner][loser] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                loseToWin[j][k] = min(loseToWin[j][k], abs(loseToWin[j][i] + loseToWin[i][k]));
                winToLose[j][k] = min(winToLose[j][k], abs(winToLose[j][i] + winToLose[i][k]));
            }
        }
    }
    for (int i = 1; i<= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (loseToWin[i][j] != INF || winToLose[i][j] != INF)
                cnt++;
        if (cnt == n - 1)
            answer++;
    }
    return answer;
}
