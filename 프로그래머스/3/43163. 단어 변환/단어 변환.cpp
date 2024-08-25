#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
map<string, int> dp;
int N;

int dfs(string curr, string &target, vector<string> words)
{
    if (curr == target)
        return 0;
    int &ret = dp[curr];
    if (ret != -1)
        return ret;
    ret = 1e9;
    for (int i = 0; i < N; i++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            string next = curr;
            next[i] = c;
            if (curr == next)
                continue ;
            if (find(words.begin(), words.end(), next) != words.end())
                ret = min(ret, dfs(next, target, words) + 1);
        }
    }
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    dp[begin] = -1;
    for (int i = 0; i < words.size(); i++)
        dp[words[i]] = -1;
    N = begin.size();
    answer = dfs(begin, target, words);
    if (answer == 1e9)
        return 0;
    return answer;
}