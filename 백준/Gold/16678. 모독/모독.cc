#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    std::sort(v.begin(), v.end());
    long long ans = 0, max = 1;
    for (int i = 0; i < N; i++)
    {
        if (v[i] > max)
            ans += v[i] - max;
        else if (v[i] < max)
            continue ;
        max++;
    }
    std::cout << ans << '\n';
}