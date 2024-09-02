#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
priority_queue<ll> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for (int i = 0; i < works.size(); i++)
        pq.push(works[i]);
    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
            break ;
        ll tmp = pq.top();
        pq.pop();
        if (tmp != 1)
            pq.push(tmp - 1);
    }
    while (!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}