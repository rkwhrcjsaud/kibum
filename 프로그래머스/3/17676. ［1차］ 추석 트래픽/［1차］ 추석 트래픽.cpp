#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int dp[24 * 60 * 60 * 1000 + 1];

void insertData(const string &str)
{
    int h = stoi(str.substr(11, 2));
    int m = stoi(str.substr(14, 2));
    int s = stoi(str.substr(17, 2));
    int ss = stoi(str.substr(20, 3));
    
    double nss = stod(str.substr(24)) * 1000;
    
    int start, end;
    start = h;
    start = start * 60 + m;
    start = start * 60 + s;
    start = start * 1000 + ss;
    end = start;
    end -= (int)nss - 1;
    start += 1;
    end -= 999;
    if (end < 0)
        end = 0;
    if (start > 24 * 60 * 60 * 1000)
        start = 24 * 60 * 60 * 1000;
    dp[end]++;
    dp[start]--;
}

int solution(vector<string> lines) {
    int answer = 0;
    for (int i = 0; i < lines.size(); i++)
        insertData(lines[i]);
    for (int i = 1; i < 24 * 60 * 60 * 1000; i++)
        dp[i] += dp[i - 1];
    for (int i = 0; i < 24 * 60 * 60 * 1000; i++)
        answer = max(answer, dp[i]);
    return answer;
}