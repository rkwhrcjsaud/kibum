#include <iostream>
#include <climits>

long long N;
long long arr[20][20];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (long long i = 0; i < N; i++)
        for (long long j = 0; j < N; j++)
            std::cin >> arr[i][j];
    long long ans = LLONG_MIN;
    for (long long i = 0; i < (1 << N); i++)
    {
        long long min = 0;
        for (long long j = 0; j < N; j++)
        {
            long long color = 0;
            long long nocolor = 0;
            for (int k = 0; k < N; k++)
            {
                if (i & (1 << k))
                    color += arr[k][j];
                else
                    nocolor += arr[k][j];
            }
            min += color < nocolor ? color : nocolor;
        }
        if (ans < min)
            ans = min;
    }
    std::cout << ans << '\n';
}