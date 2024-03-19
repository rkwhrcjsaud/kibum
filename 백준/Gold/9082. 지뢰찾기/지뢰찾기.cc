#include <iostream>

int T;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        int N;
        std::cin >> N;
        std::string num;
        std::string mine;
        std::cin >> num >> mine;
        int ans1 = 0;
        int ans2 = 0;
        bool visited[101] = {false, };
        for (int i = 0; i < N; i++)
        {
            if (mine[i] == '*')
            {
                ans1++;
                ans2++;
                if (i - 1 >= 0)
                    num[i - 1]--;
                if (i + 1 < N)
                    num[i + 1]--;
                num[i]--;
                visited[i + 1] = true;
            }
        }
        std::string num1 = "0" + num + "1";
        std::string num2 = "1" + num + "1";
        for (int i = 1; i <= N; i++)
        {
            if (num1[i] > '0' && num1[i + 1] > '0' && num1[i - 1] > '0' && !visited[i])
            {
                ans1++;
                num1[i]--;
                num1[i + 1]--;
                num1[i - 1]--;
            }
        }
        for (int i = 1; i <= N; i++)
        {
            if (num2[i] > '0' && num2[i + 1] > '0' && num2[i - 1] > '0' && !visited[i])
            {
                ans2++;
                num2[i]--;
                num2[i + 1]--;
                num2[i - 1]--;
            }
        }
        std::cout << std::max(ans1, ans2) << '\n';
    }
}