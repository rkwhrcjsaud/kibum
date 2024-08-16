#include <string>
#include <vector>

using namespace std;
int dp[151][151];
int alp_max = 0;
int cop_max = 0;

int sol(int alp, int cop, vector<vector<int>> &problems)
{
    if (alp > 150)
        alp = 150;
    if (cop > 150)
        cop = 150;
    if (alp >= alp_max && cop >= cop_max)
        return 0;
    int &ret = dp[alp][cop];
    if (ret != -1)
        return ret;
    ret = 1000000000;
    ret = min(ret, sol(alp + 1, cop, problems) + 1);
    ret = min(ret, sol(alp, cop + 1, problems) + 1);
    for (int i = 0; i < problems.size(); i++)
    {
        int alp_req = problems[i][0];
        int cop_req = problems[i][1];
        if (alp_req <= alp && cop_req <= cop)
            ret = min(ret, sol(alp + problems[i][2], cop + problems[i][3], problems) + problems[i][4]);
    }
    return ret;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    for (int i = 0; i <= 150; i++)
        for (int j = 0; j <= 150; j++)
            dp[i][j] = -1;
    
    for (int i = 0; i < problems.size(); i++)
    {
        int alp_req = problems[i][0];
        int cop_req = problems[i][1];
        alp_max = max(alp_max, alp_req);
        cop_max = max(cop_max, cop_req);
    }
    answer = sol(alp, cop, problems);
    return answer;
}