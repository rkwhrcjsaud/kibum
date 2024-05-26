#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

typedef long long ll;
ll N, S, E;
ll pibo[51];
std::string s, e;

void solve(int n, ll idx, char c)
{
    if (c == 'S')
    {
        if (idx == S)
            return ;
        if (idx + pibo[n - 2] >= S)
        {
            s += 'L';
            solve(n - 2, idx + 1, 'S');
            return ;
        }
        else
        {
            s += 'R';
            solve(n - 1, idx + pibo[n - 2] + 1, 'S');
            return ;
        }
    }
    else
    {
        if (idx == E)
            return ;
        if (idx + pibo[n - 2] >= E)
        {
            e += 'L';
            solve(n - 2, idx + 1, 'E');
            return ;
        }
        else
        {
            e += 'R';
            solve(n - 1, idx + pibo[n - 2] + 1, 'E');
            return ;
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> S >> E;
    if (N <= 1)
        return 0;
    pibo[0] = 1;
    pibo[1] = 1;
    for (int i = 2; i <= N; i++)
        pibo[i] = pibo[i - 1] + pibo[i - 2] + 1;
    solve(N, 1, 'S');
    solve(N, 1, 'E');
    int i = 0;
    for (; i < std::min(s.size(), e.size()); i++)
    {
        if (s[i] != e[i])
            break;
    }
    for (int j = i; j < s.size(); j++)
        std::cout << 'U';
    for (int j = i; j < e.size(); j++)
        std::cout << e[j];
    std::cout << '\n';
}
