#include <iostream>

long long N, B, C;
long long arr[1000010];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> B >> C;
    long long sum = 0;
    long long cnt2 = B + C > B * 2 ? B * 2 : B + C;
    long long cnt3 = B + C * 2 > B * 3 ? B * 3 : B + C * 2;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    for (int i = 0; i < N; i++)
    {
        long long tmp = 0;
        if (arr[i + 1] > arr[i + 2])
        {
            tmp = arr[i] > arr[i + 1] - arr[i + 2] ? arr[i + 1] - arr[i + 2] : arr[i];
            arr[i] -= tmp;
            arr[i + 1] -= tmp;
            sum += tmp * cnt2;
            tmp = arr[i] > arr[i + 2] ? arr[i + 2] : arr[i];
            arr[i] -= tmp;
            arr[i + 1] -= tmp;
            arr[i + 2] -= tmp;
            sum += tmp * cnt3;
            if (arr[i] != 0)
                sum += arr[i] * B;
        }
        else
        {
            tmp = arr[i] > arr[i + 1] ? arr[i + 1] : arr[i];
            arr[i] -= tmp;
            arr[i + 1] -= tmp;
            arr[i + 2] -= tmp;
            sum += tmp * cnt3;
            if (arr[i] != 0)
                sum += arr[i] * B;
        }
    }
    std::cout << sum << '\n';
}