#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
int w[10];
std::vector<int> v[150];
std::vector<long long> ans;

bool check(int n)
{
    bool visited[10] = {false, };
    while (n)
    {
        if (n % 10 != 0)
        {
            if (!w[n % 10] && n % 10 != 0)
                return true;
            if (visited[n % 10])
                return true;
        }
        visited[n % 10] = true;
        n /= 10;
    }
    return false;
}

int calc_bit(int n)
{
    int bit = 0;
    while (n)
    {
        if (n % 10 != 0)
            bit |= 1 << (n % 10);
        n /= 10;
    }
    return bit;
}

int calc_w(int n)
{
    int ret = 0;
    for (int i = 1; i <= 5 && n; i++)
    {
        ret += i * (n % 10);
        n /= 10;
    }
    return ret;
}

int reverse(int n)
{
    int ret = 0;
    for (int i = 1; i <= 5; i++)
    {
        ret *= 10;
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        std::cin >> tmp;
        w[tmp] = 1;
    }
    std::cin >> K;
    for (int i = 0; i <= 98765; i++)
    {
        if (check(i))
            continue ;
        v[calc_w(i)].push_back(i);
    }
    for (int i = 1; i <= 115; i++)
    {
        if (v[i].size() < 2)
            continue ;
        for (int j = 0; j < v[i].size(); j++)
        {
            for (int k = j + 1; k < v[i].size(); k++)
            {
                if (calc_bit(v[i][j]) & calc_bit(v[i][k]))
                    continue ;
                ans.push_back(v[i][j] * 1LL * 100000 + reverse(v[i][k]));
                ans.push_back(v[i][k] * 1LL * 100000 + reverse(v[i][j]));
            }
        }
    }
    ans.push_back(0);
    std::sort(ans.begin(), ans.end());
    if (K >= ans.size())
    {
        std::cout << ans[ans.size() - 1] << '\n';
        return 0;
    }
    std::cout << ans[K] << '\n';
}