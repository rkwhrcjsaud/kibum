#include <iostream>
#include <vector>

int N, K;
std::vector<int> v;
bool visited[200001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        v.push_back(n);
    }
    for (int i = 19; i >= 0; i--)
    {
        int tmp = 0;
        for (int j = 0; j < N; j++)
        {
            if (v[j] & (1 << i) && !visited[j])
                tmp++;
        }
        if (tmp >= K)
        {
            for (int j = 0; j < N; j++)
            {
                if (!(v[j] & (1 << i)))
                    visited[j] = true;
            }
        }
        if (tmp == K)
            break ;
    }
    int sum = (1 << 20) - 1;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            sum &= v[i];
    }
    std::cout << sum << '\n';
}
