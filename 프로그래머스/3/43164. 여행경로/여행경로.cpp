#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;
map<string, set<string>> m;
map<string, int> m2;
stack<string> s;
map<string, int> remain;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    for (int i = 0; i < tickets.size(); i++)
    {
        m[tickets[i][0]].insert(tickets[i][1]);
        m2[tickets[i][1]] = 0;
        m2[tickets[i][0]] = 0;
        remain[tickets[i][0] + tickets[i][1]]++;
    }
    
    s.push("ICN");
    while (!s.empty())
    {
        string curr = s.top();
        int &idx = m2[curr];
        if (idx == m[curr].size())
        {
            answer.push_back(curr);
            s.pop();
        }
        else
        {
            set<string>::iterator it = m[curr].begin();
            advance(it, idx);
            s.push(*it);
            remain[curr + *it]--;
            if (remain[curr + *it] <= 0)
                idx++;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}