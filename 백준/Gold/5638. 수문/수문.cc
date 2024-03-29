#include <iostream>
#include <vector>
#include <climits>

long long N, M;
std::vector<std::pair<long long, long long> > v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (long long i = 0; i < N; i++)
    {
        long long a, b;
        std::cin >> a >> b;
        v.push_back(std::make_pair(a, b));
    }
    std::cin >> M;
    long long num = 1;
    while (M--)
    {
        long long V, T;
        std::cin >> V >> T;
        long long minw = LLONG_MAX;
        std::cout << "Case " << num++ << ": ";
        for (long long i = 0; i < (1 << N); i++)
        {
            long long sum = 0;
            long long w = 0;
            for (long long j = 0; j < N; j++)
            {
                if (i & (1 << j))
                {
                    sum += v[j].first;
                    w += v[j].second;
                }
            }
            if (sum * T >= V && w < minw)
                minw = w;
        }
        if (minw == LLONG_MAX)
            std::cout << "IMPOSSIBLE\n";
        else
            std::cout << minw << '\n';
    }
}