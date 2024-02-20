#include <iostream>
#include <vector>

int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    int max = 0;
    int maxcnt = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (max <= tmp)
        {
            max = tmp;
            cnt = 0;
        }
        else
        {
            cnt++;
            maxcnt < cnt ? maxcnt = cnt : 0;
        }
    }
    std::cout << maxcnt + 1 << std::endl;
}