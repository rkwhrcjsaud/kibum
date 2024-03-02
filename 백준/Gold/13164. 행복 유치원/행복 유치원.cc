#include <iostream>
#include <queue>

int N, K;
std::priority_queue<int> pq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    int prev;
    int answer = 0;
    std::cin >> prev;
    for (int i = 0; i < N - 1; i++)
    {
        int curr;
        std::cin >> curr;
        pq.push(curr - prev);
        prev = curr;
    }
    for (int i = 0; i < K - 1 && !pq.empty(); i++)
        pq.pop();
    for (; !pq.empty(); pq.pop())
        answer += pq.top();
    std::cout << answer << '\n';
}
