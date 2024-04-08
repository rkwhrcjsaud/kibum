#include <iostream>

int N, max;
int arr[50];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            double slope = (double)(arr[i] - arr[j]) / (i - j);
            bool flag = true;
            for (int k = j + 1; k < i; k++)
            {
                if (slope * (k - j) + arr[j] <= arr[k])
                {
                    flag = false;
                    break ;
                }
            }
            if (flag)
                cnt++;
        }
        for (int j = i + 1; j < N; j++)
        {
            double slope = (double)(arr[j] - arr[i]) / (j - i);
            bool flag = true;
            for (int k = i + 1; k < j; k++)
            {
                if (slope * (k - i) + arr[i] <= arr[k])
                {
                    flag = false;
                    break ;
                }
            }
            if (flag)
                cnt++;
        }
        max = std::max(max, cnt);
    }
    std::cout << max << '\n';
}