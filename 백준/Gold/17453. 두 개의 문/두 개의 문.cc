#include <iostream>
#include <vector>
#include <bitset>

int N, M;
std::bitset<100> origin;
std::bitset<100> arr[21];
std::vector<std::bitset<20> > v[210];

void solution(int idx, std::bitset<20> bit, std::bitset<100> door)
{
    if (idx == M)
    {
        v[100 - N + door.count() * 2].push_back(bit);
        return ;
    }
    solution(idx + 1, bit, door);
    solution(idx + 1, bit.set(idx), door ^ arr[idx]);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    std::cin >> origin;
    for (int i = 0; i < M; i++)
        std::cin >> arr[i];
    solution(0, 0, origin);
    for (int i = 100 - N; i <= 100 + N; i++)
    {
        if (v[i].empty())
        {
            std::cout << -1 << '\n';
            continue ;
        }
        std::cout << v[i][0].count() << ' ';
        for (int j = 0; j < 20; j++)
        {
            if (v[i][0].test(j))
                std::cout << j + 1 << ' ';
        }
        std::cout << '\n';
    }
}