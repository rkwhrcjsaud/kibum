#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct compare {
    int operator()(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    };
};

int comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int s = 0;
    int N = jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    while (1)
    {
        if (pq.empty() && s <= jobs[0][0])
        {
            s = jobs[0][0] + jobs[0][1];
            answer += jobs[0][1];
            jobs.erase(jobs.begin());
        }
        while (!jobs.empty() && s > jobs[0][0])
        {
            pq.push(jobs[0]);
            jobs.erase(jobs.begin());
        }
        if (!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            answer += curr[1] + s - curr[0];
            s += curr[1];
        }
        if (pq.empty() && jobs.empty())
            break ;
    }
    answer /= N;
    return answer;
}