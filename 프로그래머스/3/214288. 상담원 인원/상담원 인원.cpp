#include <string>
#include <vector>
#include <iostream>

using namespace std;
int N, K;
int dp[6][21];

int calc_time(int k, int n, vector<vector<int>> &reqs)
{
    vector<int> v(n, 0);
    
    int ret = 0;
    
    for (int i = 0; i < N; i++)
    {
        if (reqs[i][2] != k)
            continue;
        int start = reqs[i][0];
        int time = reqs[i][1];
        int min_idx = 0;
        int min_time = 40000000;
        for (int j = 0; j < n; j++)
        {
            int tmp = v[j] - start;
            if (tmp < min_time)
            {
                min_time = tmp;
                min_idx = j;
            }
        }
        if (min_time <= 0)
            v[min_idx] = start + time;
        else
        {
            v[min_idx] = start + time + min_time;
            ret += min_time;
        }
    }
    return ret;
}

int calc_answer(int n, vector<int> v)
{
    if (n == 0)
        return 0;
    int min = 0;
    int min_idx = 1;
    for (int i = 1; i <= K; i++)
    {
        int tmp = dp[i][v[i]] - dp[i][v[i] + 1];
        if (tmp > min)
        {
            min = tmp;
            min_idx = i;
        }
    }
    v[min_idx]++;
    return min + calc_answer(n - 1, v);
}

int solution(int k, int n, vector<vector<int>> reqs) {
    N = reqs.size();
    K = k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = calc_time(i, j, reqs);
        }
    }
    
    vector<int> tmp(k + 1, 1);
    int answer = 0;
    for (int i = 1; i <= k; i++)
        answer += dp[i][1];
    answer -= calc_answer(n - k, tmp);
    return answer;
}