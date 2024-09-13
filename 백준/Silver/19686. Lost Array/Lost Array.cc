#include <iostream>
#include <vector>
#include <algorithm>

int N, M;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    std::vector<int> v(N + 1, 1);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (v[a] < c)
            v[a] = c;
        if (v[b] < c)
            v[b] = c;
    }
    for (int i = 1; i <= N; i++)
        std::cout << v[i] << ' ';
}