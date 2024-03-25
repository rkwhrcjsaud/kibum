#include <iostream>
#include <vector>

int N;
std::vector<int> v[18];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (i & 1 << j)
                v[j].push_back(i);
        }
    }
    int K = 0;
    for (int i = 0; i < 18; i++)
    {
        if (v[i].size() > 1)
            K++;
    }
    std::cout << K << '\n';
    for (int i = 0; i < 18; i++)
    {
        if (v[i].size() <= 1)
            continue ;
        std::cout << v[i].size() << ' ';
        for (int j = 0; j < v[i].size(); j++)
            std::cout << v[i][j] << ' ';
        std::cout << '\n';
    }
}