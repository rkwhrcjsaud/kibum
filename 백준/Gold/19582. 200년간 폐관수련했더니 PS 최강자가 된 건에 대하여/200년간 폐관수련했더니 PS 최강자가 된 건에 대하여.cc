#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
std::vector<std::pair<long long, long long> > v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v.push_back(std::make_pair(a, b));
    }
    int flag = 1;
    long long max_money = 0;
    long long curr_money = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (curr_money <= v[i].first)
        {
            cnt++;
            curr_money += v[i].second;
            max_money = std::max(max_money, v[i].second);
        }
        else if (flag == 1)
        {
            flag = 0;
            if (max_money <= v[i].second)
                continue ;
            curr_money -= max_money;
            if (curr_money <= v[i].first)
                curr_money += v[i].second;
            else
                curr_money += max_money;
        }
        else
            break ;
    }
    if (cnt >= N - 1)
        std::cout << "Kkeo-eok" << '\n';
    else
        std::cout << "Zzz" << '\n';
}
