#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, K;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> K;
    vector<pair<int, int> > jewel(N);
    vector<int> bag(K);
    for (int i = 0; i < N; i++)
        cin >> jewel[i].first >> jewel[i].second;
    for (int i = 0; i < K; i++)
        cin >> bag[i];
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());
    long long sum = 0;
    priority_queue<int> pq;
    for (int i = 0, j = 0; i < K; i++)
    {
        while (j < N && jewel[j].first <= bag[i])
        {
            pq.push(jewel[j].second);
            j++;
        }
        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << '\n';
}