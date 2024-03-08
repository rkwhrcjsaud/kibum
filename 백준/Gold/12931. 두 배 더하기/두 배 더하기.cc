#include <iostream>
#include <vector>

int N;
long long sum;
std::vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    long long maxdevide = 0;
    for (int i = 0; i < N; i++)
    {
        long long devide = 0;
        while (v[i] != 0)
        {
            if (v[i] % 2)
            {
                v[i]--;
                sum++;
            }
            if (v[i] == 0)
                break ;
            v[i] /= 2;
            devide++;
        }
        maxdevide = std::max(maxdevide, devide);
    }
    sum += maxdevide;
    std::cout << sum << '\n';
}
