#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int N, M, K;
std::vector<double> arr(101, 0);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int i;
            double s;
            std::cin >> i >> s;
            arr[i] = std::max(arr[i], s);
        }
    }
    std::sort(arr.begin(), arr.end(), std::greater<double>());
    double ans = 0;
    for (int i = 0; i < K; i++)
        ans += arr[i];
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << ans << '\n';
}