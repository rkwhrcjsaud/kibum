#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;
vector<int> v[10001];
int isChild[10001];
int K = 0;

int sol(int lim, int node, vector<int> &num)
{
    priority_queue<int> pq;
    int sum = 0;
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        int tmp = sol(lim, next, num);
        pq.push(tmp);
        sum += tmp;
    }
    while (!pq.empty() && sum + num[node] > lim)
    {
        K++;
        sum -= pq.top();
        pq.pop();
    }
    return sum + num[node];
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 1e9;
    int max_num = 0;
    for (int i = 0; i < links.size(); i++)
    {
        max_num = max(max_num, num[i]);
        if (links[i][0] != -1)
        {
            v[i].push_back(links[i][0]);
            isChild[links[i][0]] = true;
        }
        if (links[i][1] != -1)
        {
            v[i].push_back(links[i][1]);
            isChild[links[i][1]] = true;
        }
    }
    int root = -1;
    for (int i = 0; i < num.size(); i++)
        if (!isChild[i])
            root = i;
    int s = max_num, e = 1e9;
    while (e >= s)
    {
        int mid = (s + e) / 2;
        K = 0;
        sol(mid, root, num);
        if (K < k)
        {
            e = mid - 1;
            answer = min(answer, mid);
        }
        else
            s = mid + 1;
    }
    return answer;
}