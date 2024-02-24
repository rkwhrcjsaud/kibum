#include <iostream>
#include <vector>

int N, M;
std::vector< std::pair< int, int> > v;

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
    std::cin >> M;
    std::vector<int> v2;
    for (int i = 0; i <= M; i++)
    {
        int total = i;
        int num = i * v[0].first + v[0].second;
        v2.push_back(i);
        for (int j = 1; j < N; j++)
        {
            if ((num - v[j].second) % v[j].first != 0)
                break;
            else
            {
                v2.push_back((num - v[j].second) / v[j].first);
                total += v2.back();
            }
            if (total > M)
                break ;
        }
        if (total == M && v2.size() == N)
        {
            std::cout << v[0].first * i + v[0].second << '\n';
            return 0;
        }
        v2.clear();
    }
    std::cout << '0' << '\n';
}