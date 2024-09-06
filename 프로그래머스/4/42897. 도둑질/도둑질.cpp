#include <string>
#include <vector>

using namespace std;
int dp1[1000001][2];
int dp2[1000001][2];
int dp3[1000001][2];

int solution(vector<int> money) {
    int answer = 0;
    dp1[0][0] = money[0];
    for (int i = 1; i < money.size() - 1; i++)
    {
        dp1[i][0] = max(dp1[i - 1][1] + money[i], dp1[i - 1][0]);
        dp1[i][1] = max(dp1[i - 1][0], dp1[i - 1][1]);
    }
    answer = max(answer, dp1[money.size() - 2][0]);
    answer = max(answer, dp1[money.size() - 2][1]);
    dp2[0][1] = money[money.size() - 1];
    for (int i = 1; i < money.size() - 2; i++)
    {
        dp2[i][0] = max(dp2[i - 1][1] + money[i], dp2[i - 1][0]);
        dp2[i][1] = max(dp2[i - 1][0], dp2[i - 1][1]);
    }
    answer = max(answer, dp2[money.size() - 3][0]);
    answer = max(answer, dp2[money.size() - 3][1]);
    dp3[1][0] = money[1];
    for (int i = 2; i < money.size() - 1; i++)
    {
        dp3[i][0] = max(dp3[i - 1][1] + money[i], dp3[i - 1][0]);
        dp3[i][1] = max(dp3[i - 1][0], dp3[i - 1][1]);
    }
    answer = max(answer, dp3[money.size() - 2][0]);
    answer = max(answer, dp3[money.size() - 2][1]);
    return answer;
}