#include <iostream>
#include <vector>

int N, M;
std::vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    int start = 0;
    int end = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        std::cin >> a;
        v.push_back(a);
        if (a > start)
            start = a;
        end += a;
    }
    int ans = 10000000;
    std::vector<int> ansv;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int max = 0;
        std::vector<int> tmp;
        for (int i = 0; i < N;)
        {
            int sum = 0;
            int cnt = 0;
            while (i < N && sum + v[i] <= mid)
            {
                cnt++;
                sum += v[i];
                i++;
                if (M - (int)tmp.size() == N - i + 1)
                    break ;
            }
            if (max < sum)
                max = sum;
            tmp.push_back(cnt);
        }
        if ((int)tmp.size() > M)
            start = mid + 1;
        else
        {
            if (ans > max && (int)tmp.size() == M)
            {
                ans = max;
                ansv = tmp;
            }
            end = mid - 1;
        }
    }
    std::cout << ans << '\n';
    for (int i = 0; i < (int)ansv.size(); i++)
        std::cout << ansv[i] << ' ';
    std::cout << '\n';
}
