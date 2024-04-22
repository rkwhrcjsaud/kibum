#include <iostream>
#include <map>

long long N, X;
long long hambuger[51];
long long paty[51];

long long solve(int level, long long layer)
{
    if (level == 0)
    {
        if (layer == 1)
            return 1;
        else if (layer == 0)
            return 0;
    }

    if (layer == 1)
        return 0;
    else if (layer <= 1 + hambuger[level - 1])
        return solve(level - 1, layer - 1);
    else if (layer == 2 + hambuger[level - 1])
        return paty[level - 1] + 1;
    else if (layer <= 2 + 2 * hambuger[level - 1])
        return paty[level - 1] + 1 + solve(level - 1, layer - 2 - hambuger[level - 1]);
    else
        return 2 * paty[level - 1] + 1;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> X;
    hambuger[0] = paty[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        hambuger[i] = 2 * hambuger[i - 1] + 3;
        paty[i] = 2 * paty[i - 1] + 1;
    }
    std::cout << solve(N, X) << '\n';
}