#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;
vector<pair<int, int>> v[50001];

const int INF = 10000001;

pair<int, int> sol(vector<int> &gates, int n, vector<int> &summits)
{
    vector<int> w(n + 1, INF);
    priority_queue<pair<int, int>> pq;
    
    for (int i = 0; i < gates.size(); i++)
    {
        w[gates[i]] = 0;
        pq.push(make_pair(0, gates[i]));
    }
    
    while (!pq.empty())
    {
        int cur_w = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < v[cur_node].size(); i++)
        {
            int next_node = v[cur_node][i].first;
            int next_w = max(cur_w, v[cur_node][i].second);
            
            if (next_w < w[next_node])
            {
                w[next_node] = next_w;
                pq.push(make_pair(-next_w, next_node));
            }
        }
    }
    
    int intensity = INF;
    int summit = INF;
    
    for (int i = 0; i < summits.size(); i++)
    {
        if (w[summits[i]] < intensity)
        {
            intensity = w[summits[i]];
            summit = summits[i];
        }
        else if (w[summits[i]] == intensity && summits[i] < summit)
            summit = summits[i];
    }
    return make_pair(summit, intensity);
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    set<int> isGate(gates.begin(), gates.end());
    set<int> isSummit(summits.begin(), summits.end());
    for (int i = 0; i < paths.size(); i++)
    {
        int a = paths[i][0];
        int b = paths[i][1];
        int w = paths[i][2];
        if (isSummit.find(a) == isSummit.end() && isGate.find(b) == isGate.end())
            v[a].push_back(make_pair(b, w));
        if (isSummit.find(b) == isSummit.end() && isGate.find(a) == isGate.end())
            v[b].push_back(make_pair(a, w));
    }
    
    std::pair<int, int> tmp = sol(gates, n, summits);
    answer.push_back(tmp.first);
    answer.push_back(tmp.second);
    return answer;
}