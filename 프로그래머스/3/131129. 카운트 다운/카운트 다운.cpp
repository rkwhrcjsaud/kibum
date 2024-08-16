#include <string>
#include <vector>

using namespace std;
pair<int ,int> dp[100001];
const int inf = 1e9;

vector<int> solution(int target) {
    vector<int> answer;
    for (int i = 1; i <= target; i++)
        dp[i] = make_pair(inf, 0);
    for (int i = 1; i <= target; i++)
    {
        if (i <= 20)
        {
            dp[i] = make_pair(1, 1);
            continue;
        }
        if (i <= 60 && i % 3 == 0)
        {
            dp[i] = make_pair(1, 0);
            continue;
        }
        if (i <= 40 && i % 2 == 0)
        {
            dp[i] = make_pair(1, 0);
            continue;
        }
        if (i == 50)
        {
            dp[i] = make_pair(1, 1);
            continue;
        }
        
        for (int j = 1; j <= 20; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                if (i < j * k)
                    break ;
                pair<int, int> a = dp[i - j * k];
                pair<int, int> b = dp[j * k];
                if (dp[i].first > a.first + b.first)
                {
                    dp[i].first = a.first + b.first;
                    dp[i].second = a.second + b.second;
                }
                if (dp[i].first == a.first + b.first)
                {
                    if (dp[i].second < a.second + b.second)
                        dp[i].second = a.second + b.second;
                }
            }
        }
        if (i <= 50)
            continue;
        pair <int, int> aa = dp[i - 50];
        if (dp[i].first > aa.first + 1)
        {
            dp[i].first = aa.first + 1;
            dp[i].second = aa.second + 1;
        }
        if (dp[i].first == aa.first + 1)
        {
            if (dp[i].second < aa.second + 1)
                dp[i].second = aa.second + 1;
        }
    }
    answer.push_back(dp[target].first);
    answer.push_back(dp[target].second);
    return answer;
}