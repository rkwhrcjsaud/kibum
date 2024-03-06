#include <iostream>

int N;
int arr[1000001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        std::cin >> x;
        if (arr[x] == 0)
        {
            arr[x - 1]++;
            cnt++;
        }
        else
        {
            arr[x - 1]++;
            arr[x]--;
        }
    }
    std::cout << cnt << '\n';
}