#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>

int N, K;
int arr[101][10010];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            std::cin >> arr[i][j];
    std::vector<std::pair<int, int> > past;
    past.push_back(std::make_pair(0, 0));
    past.push_back(std::make_pair(0, 0));
    for (int i = 0; i < N; i++)
    {
        int first = past[0].first;
        int first_idx = past[0].second;
        int second = past[1].first;
        int second_idx = past[1].second;

        std::priority_queue<std::pair<int, int> > pq;
        for (int j = 0; j < K; j++)
        {
            if (j != first_idx)
                pq.push(std::make_pair(first + arr[i][j], j));
            else
                pq.push(std::make_pair(second + arr[i][j], j));
        }

        past[0] = pq.top();
        pq.pop();
        past[1] = pq.top();
        pq.pop();
    }
    std::cout << past[0].first << '\n';
}