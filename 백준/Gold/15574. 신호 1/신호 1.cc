#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int N;
std::vector< std::pair<int ,int> > v;
std::vector< int > tmp;
std::pair<int, int> arr[1001];
std::vector< int > idxToNum;
double dp[1001][2];

double solve(int idx, int flag)
{
    if (idx == N - 1)
        return 0;
    double &ret = dp[idx][flag];
    if (ret != -1)
        return ret;
    ret = 0;
    long long x = std::pow(idxToNum[idx + 1] - idxToNum[idx], 2);
    if (flag == 0)
    {
        ret = std::max(ret, solve(idx + 1, 0) + std::sqrt(x + std::pow(std::abs(arr[idx].first - arr[idx + 1].first), 2)));
        ret = std::max(ret, solve(idx + 1, 1) + std::sqrt(x + std::pow(std::abs(arr[idx].first - arr[idx + 1].second), 2)));
    }
    else
    {
        ret = std::max(ret, solve(idx + 1, 0) + std::sqrt(x + std::pow(std::abs(arr[idx].second - arr[idx + 1].first), 2)));
        ret = std::max(ret, solve(idx + 1, 1) + std::sqrt(x + std::pow(std::abs(arr[idx].second - arr[idx + 1].second), 2)));
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        tmp.push_back(a);
        v.push_back(std::make_pair(a, b));
    }
    std::sort(tmp.begin(), tmp.end());
    tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
    N = tmp.size();
    for (int i = 0; i < N; i++)
    {
        arr[i].first = -1e9;
        arr[i].second = 1e9;
    }
    for (int i = 0; i < N; i++)
        idxToNum.push_back(tmp[i]);
    for (int i = 0; i < v.size(); i++)
    {
        int idx = std::lower_bound(tmp.begin(), tmp.end(), v[i].first) - tmp.begin();
        arr[idx].first = std::max(arr[idx].first, v[i].second);
        arr[idx].second = std::min(arr[idx].second, v[i].second);
    }
    std::cout << std::fixed;
    std::cout.precision(7);
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    std::cout << std::max(solve(0, 1), solve(0, 0)) << "\n";
}