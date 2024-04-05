#include <iostream>

int T, N;

bool calc(std::string str)
{
    int sum = 0;
    char op = '+';
    int num = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
            continue ;
        if (str[i] == '+' || str[i] == '-')
        {
            if (op == '+')
                sum += num;
            else
                sum -= num;
            num = 0;
            op = str[i];
        }
        else
            num = num * 10 + (str[i] - '0');
    }
    if (op == '+')
        sum += num;
    else
        sum -= num;
    return sum == 0;
}

void solve(std::string str, int idx)
{
    if (idx == N + 1)
    {
        if (calc(str))
            std::cout << str << '\n';
        return ;
    }
    std::string num = "0";
    num[0] += idx;
    solve(str + " " + num, idx + 1);
    solve(str + "+" + num, idx + 1);
    solve(str + "-" + num, idx + 1);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        solve("1", 2);
        std::cout << '\n';
    }
}