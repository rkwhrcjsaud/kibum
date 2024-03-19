#include <iostream>
#include <queue>
#include <climits>

int N;
std::priority_queue<long long, std::vector<long long>, std::greater<long long> > pq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    long long max = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (max < tmp) max = tmp;
        pq.push(tmp);
    }
    long long ans = LLONG_MAX;
    while (1)
    {
        long long a = pq.top();
        pq.pop();
        if (ans > max - a)
            ans = max - a;
        if (ans * 2 == max - a)
            break ;
        pq.push(a * 2);
        if (max < a * 2) max = a * 2;
    }
    std::cout << ans << '\n';
}