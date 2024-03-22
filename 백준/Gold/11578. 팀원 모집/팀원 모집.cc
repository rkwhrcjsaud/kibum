#include <iostream>
#include <vector>

int N, M, ans = 0x7fffffff;
std::vector<int> people;

void solved(int idx, int mask, int cnt)
{
    if (idx == M)
    {
        if (mask == (1 << N) - 1)
            ans = std::min(ans, cnt);
        return ;
    }
    if (cnt >= ans)
        return ;
    solved(idx + 1, mask | people[idx], cnt + 1);
    solved(idx + 1, mask, cnt);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    int mask = 0;
    for (int i = 0; i < M; i++)
    {
        int n, bit = 0;
        std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            int tmp;
            std::cin >> tmp;
            bit |= (1 << (tmp - 1));
        }
        people.push_back(bit);
        mask |= bit;
    }
    if (mask != (1 << N) - 1)
    {
        std::cout << "-1\n";
        return 0;
    }
    solved(0, 0, 0);
    std::cout << ans << '\n';
}
