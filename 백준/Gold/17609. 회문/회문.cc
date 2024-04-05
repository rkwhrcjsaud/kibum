#include <iostream>

int N;
std::string str;

int solve(int left, int right)
{
    while (left < right)
    {
        if (str[left] != str[right])
            return 2;
        left++;
        right--;
    }
    return 1;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> str;
        int left = 0, right = str.size() - 1;
        int flag = 0;
        while (left < right)
        {
            if (str[left] != str[right])
            {
                if (flag == 0)
                {
                    flag = std::min(solve(left + 1, right), solve(left, right - 1));
                    break ;
                }
                else if (flag == 1)
                {
                    flag = 2;
                    break ;
                }
            }
            left++;
            right--;
        }
        std::cout << flag << '\n';
    }
}