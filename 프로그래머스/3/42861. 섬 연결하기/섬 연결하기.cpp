#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int parent[101];

int compare(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find(int a)
{
    if (a != parent[a])
        return parent[a] = find(parent[a]);
    return parent[a];
}

void merge(int a, int b)
{
    int aa = find(a);
    int bb = find(b);
    parent[aa] = bb;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;
    sort(costs.begin(), costs.end(), compare);
    for (int i = 0; i < costs.size(); i++)
    {
        int a = find(costs[i][0]);
        int b = find(costs[i][1]);
        int w = costs[i][2];
        if (a == b)
            continue ;
        answer += w;
        merge(a, b);
    }
    return answer;
}