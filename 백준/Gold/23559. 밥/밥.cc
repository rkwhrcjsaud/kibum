#include <iostream>
#include <vector>
#include <algorithm>

int N, X;
std::vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> X;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        ans += b;
        v.push_back(a - b);
    }
    std::sort(v.begin(), v.end(), std::greater<int>());
    int money = (X - N * 1000) / 4000;
    for (int i = 0; i < N; i++)
    {
        if (v[i] <= 0 || money <= 0)
            break ;
        ans += v[i];
        money--;
    }
    std::cout << ans << '\n';
}