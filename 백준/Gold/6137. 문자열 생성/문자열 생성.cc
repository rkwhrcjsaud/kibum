#include <iostream>

int N;
char arr[2020];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    int fidx = 0;
    int bidx = N - 1;
    std::string ans = "";
    while (fidx <= bidx)
    {
        if (arr[fidx] < arr[bidx])
        {
            ans += arr[fidx];
            fidx++;
        }
        else if (arr[fidx] > arr[bidx])
        {
            ans += arr[bidx];
            bidx--;
        }
        else
        {
            int tmpf = fidx;
            int tmpb = bidx;
            while (tmpf < tmpb && arr[tmpf] == arr[tmpb])
            {
                tmpf++;
                tmpb--;
            }
            if (arr[tmpf] < arr[tmpb])
            {
                ans += arr[fidx];
                fidx++;
            }
            else
            {
                ans += arr[bidx];
                bidx--;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << ans[i];
        if (i % 80 == 79)
            std::cout << '\n';
    }
}