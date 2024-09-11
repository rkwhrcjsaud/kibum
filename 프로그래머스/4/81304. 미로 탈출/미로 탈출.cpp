#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<int, int> trapOrder;
vector<pair<int, int>> v[1001][2];
int isReverse[1 << 10];
int dp[1001][1 << 10];

struct edge {
    int node;
    int bit;
    int t;
    edge(int node, int bit, int t) : node(node), bit(bit), t(t) {};
};

struct compare {
    bool operator()(const edge &a, const edge &b) {
        return a.t > b.t;
    };
};

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < traps.size(); i++)
        trapOrder[traps[i]] = i;
    for (int i = 0; i < roads.size(); i++)
    {
        v[roads[i][0]][0].push_back(make_pair(roads[i][1], roads[i][2]));
        v[roads[i][1]][1].push_back(make_pair(roads[i][0], roads[i][2]));
    }
    priority_queue<edge, vector<edge>, compare> pq;
    pq.push(edge(start, 0, 0));
    while (!pq.empty())
    {
        edge curr = pq.top();
        if (curr.node == end)
            return curr.t;
        pq.pop();
        for (int dir = 0; dir <= 1; dir++)
        {
            for (int i = 0; i < v[curr.node][dir].size(); i++)
            {
                int next = v[curr.node][dir][i].first;
                int nextBit = curr.bit;
                int dist = curr.t + v[curr.node][dir][i].second;
                int tmp = 0;
                if (trapOrder.find(curr.node) != trapOrder.end() && (curr.bit & (1 << trapOrder[curr.node])))
                    tmp |= 2;
                if (trapOrder.find(next) != trapOrder.end() && (curr.bit & (1 << trapOrder[next])))
                    tmp |= 1;
                if (dir == 1 && (tmp == 3 || tmp == 0))
                    continue ;
                if (dir == 0 && (tmp == 1 || tmp == 2))
                    continue ;
                if (trapOrder.find(next) != trapOrder.end())
                    nextBit ^= (1 << trapOrder[next]);
                if (dp[next][nextBit] != -1 && dp[next][nextBit] < dist)
                    continue ;
                dp[next][nextBit] = dist;
                pq.push(edge(next, nextBit, dist));
            }
        }
    }
    return answer;
}
