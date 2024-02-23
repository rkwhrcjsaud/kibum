#include <iostream>

long long N;

long long solution(long long cnt, long long x, long long y)
{
    long long circle = N * N;
    while (x < N && y >= 0)
    {
        long long len = x * x + y * y;
        long long len2 = len + 2 * x + 1;
        if (len < circle)
        {
            cnt++;
            if (len2 < circle)
                x++;
            else if (len2 > circle)
                y--;
            else
            {
                x++;
                y--;
            }
        }
    }
    return cnt;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    N /= 2;
    std::cout << solution(0, 0, N - 1) * 4 << '\n';
}