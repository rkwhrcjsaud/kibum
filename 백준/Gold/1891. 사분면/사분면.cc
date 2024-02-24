#include <iostream>
#include <vector>
#include <cmath>

long long pos[2];
std::string str;
std::vector<int> v;
int d;

void calc_pos(void)
{
    long long num = 1;
    for (int i = d - 1; i >= 0; i--)
    {
        switch (str[i])
        {
            case '1':
                pos[0] += num;
                break;
            case '2':
                break;
            case '3':
                pos[1] += num;
                break;
            case '4':
                pos[0] += num;
                pos[1] += num;
                break;
        }
        num *= 2;
    }
}

void reverse_calc_pos(void)
{
    long long num = std::pow(2, d - 1);
    while (num > 0)
    {
        if (pos[0] > num && pos[1] > num)
        {
            v.push_back(4);
            pos[0] -= num;
            pos[1] -= num;
        }
        else if (pos[0] > num)
        {
            v.push_back(1);
            pos[0] -= num;
        }
        else if (pos[1] > num)
        {
            v.push_back(3);
            pos[1] -= num;
        }
        else
            v.push_back(2);
        num /= 2;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> d;
    std::cin >> str;
    pos[0] = 1;
    pos[1] = 1;
    long long x, y;
    std::cin >> x >> y;
    calc_pos();
    if (pos[0] < 1 - x || pos[0] > std::pow(2, d) - x || pos[1] < 1 + y || pos[1] > std::pow(2, d) + y)
    {
        std::cout << -1 << '\n';
        return 0;
    }
    pos[0] += x;
    pos[1] -= y;
    reverse_calc_pos();
    for (int i = 0; i < d; i++)
        std::cout << v[i];
    std::cout << '\n';
}