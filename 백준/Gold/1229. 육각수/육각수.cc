#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> v;
int d[1000001] = {0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 2, };

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int num = 1, j = 2; num <= N; j++)
    {
        v.push_back(num);
        num = j * (2 * j - 1);
    }
    for (int i = 13; i <= N; i++)
    {
        int min = 1e9;
        for (int j = 0; j < v.size(); j++)
        {
            if (i < v[j])
                break ;
            min = std::min(min, d[i - v[j]]);
        }
        d[i] = min + 1;
    }
    std::cout << d[N] << '\n';
}