#include <iostream>
#include <vector>
#include <algorithm>

long long M, N;
std::vector<long long> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> M >> N;
    long long total = -M;
    unsigned long long ans = 0;
    for (long long i = 0; i < N; i++)
    {
        long long tmp;
        std::cin >> tmp;
        total += tmp;
        v.push_back(tmp);
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        long long tmp = std::min(total / (N - i), v[i]);
        ans += tmp * tmp;
        total -= tmp;
    }
    std::cout << ans << '\n';
}