#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int N;
int arr[17];
double dp[1 << 16];

double solve(int bit)
{
    if (bit == (1 << N) - 1)
        return 0;
    double &ret = dp[bit];
    if (ret != 0)
        return ret;
    ret = 0;
    for (int i = 0; i < N; i++)
    {
        int next1 = bit;
        if (bit & (1 << i))
            continue;
        next1 |= (1 << i);
        for (int j = i + 1; j < N; j++)
        {
            int next2 = next1;
            if (bit & (1 << j))
                continue;
            next2 |= (1 << j);
            for (int k = j + 1; k < N; k++)
            {
                int next3 = next2;
                if (bit & (1 << k))
                    continue;
                if (arr[i] + arr[j] <= arr[k])
                    continue;
                next3 |= (1 << k);
                double p = (arr[i] + arr[j] + arr[k]) / 2.0;
                ret = std::max(ret, solve(next3) + std::sqrt(p * (p - arr[i]) * (p - arr[j]) * (p - arr[k])));
            }
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    std::sort(arr, arr + N);
    std::cout << std::fixed;
    std::cout.precision(10);
    std::cout << solve(0) << '\n';
}