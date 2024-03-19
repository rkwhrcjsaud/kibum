#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
int cur, prev;
std::vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    std::cin >> prev;
    int ans = N;
    for (int i = 1; i < N; i++)
    {
        std::cin >> cur;
        v.push_back(cur - prev - 1);
        prev = cur;
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < N - K; i++)
        ans += v[i];
    std::cout << ans << '\n';
}
