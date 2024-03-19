#include <iostream>

int N, K, mask;
int words[51];

int dfs(int depth, int idx)
{
    int ret = 0;
    if (depth == K)
    {
        for (int i = 0; i < N; i++)
            if ((words[i] & mask) == words[i])
                ret++;
        return ret;
    }
    for (int i = idx; i < 26; i++)
    {
        if (mask & (1 << i))
            continue ;
        mask |= 1 << i;
        ret = std::max(ret, dfs(depth + 1, i));
        mask &= ~(1 << i);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < s.size(); j++)
            words[i] |= 1 << (s[j] - 'a');
    }
    if (K < 5)
    {
        std::cout << "0\n";
        return 0;
    }
    mask |= 1 << ('a' - 'a');
    mask |= 1 << ('n' - 'a');
    mask |= 1 << ('t' - 'a');
    mask |= 1 << ('i' - 'a');
    mask |= 1 << ('c' - 'a');
    K -= 5;
    std::cout << dfs(0, 0) << '\n';
}