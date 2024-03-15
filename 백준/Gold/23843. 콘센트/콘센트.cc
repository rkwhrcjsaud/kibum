#include <iostream>
#include <queue>

int N, M;
std::priority_queue<int> pq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        pq.push(tmp);
    }
    int remain = 0;
    int ans = 0;
    while (!pq.empty())
    {
        int tmp = pq.top();
        pq.pop();
        if (remain == 0)
        {
            remain = tmp * (M - 1);
            ans += tmp;
        }
        else if (remain < tmp)
            pq.push(tmp - remain);
        else
            remain -= tmp;
    }
    std::cout << ans << '\n';
}