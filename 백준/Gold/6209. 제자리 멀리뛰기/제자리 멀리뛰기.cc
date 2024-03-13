#include <iostream>
#include <vector>
#include <algorithm>

int D, N, M;
std::vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> D >> N >> M;
    v.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(D);
    std::sort(v.begin(), v.end());
    int left = 0, right = D, ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = 0, last = 0;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] - last < mid)
                cnt++;
            else
                last = v[i];
        }
        if (cnt > M)
            right = mid - 1;
        else
        {
            left = mid + 1;
            ans = mid;
        }
    }
    std::cout << ans << '\n';
}