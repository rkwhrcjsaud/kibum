#include <iostream>

int N;
int arr[1010];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        arr[i] = tmp - arr[i];
    }
    int ans = 0;
    for (int i = 0; i < N;)
    {
        if (arr[i] < 0)
        {
            for (int j = i; j < N; j++)
            {
                if (arr[j] >= 0)
                    break ;
                arr[j]++;
            }
            ans++;
        }
        else if (arr[i] == 0)
        {
            i++;
            continue ;
        }
        else
        {
            for (int j = i; j < N; j++)
            {
                if (arr[j] <= 0)
                    break ;
                arr[j]--;
            }
            ans++;
        }
    }
    std::cout << ans << '\n';
}