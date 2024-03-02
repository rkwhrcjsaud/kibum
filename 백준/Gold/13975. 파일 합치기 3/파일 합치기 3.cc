#include <iostream>
#include <queue>

int T;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        long long N;
        std::cin >> N;
        std::priority_queue<long long, std::vector<long long>, std::greater<long long> > pq;
        for (long long i = 0; i < N; i++)
        {
            long long tmp;
            std::cin >> tmp;
            pq.push(tmp);
        }
        long long result = 0;
        while (pq.size() != 1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            result += a + b;
            pq.push(a + b);
        }
        std::cout << result << '\n';
    }
}