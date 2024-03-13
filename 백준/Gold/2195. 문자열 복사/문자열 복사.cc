#include <iostream>

std::string S, P;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> S >> P;
    int ans = 0;
    for (int i = 0; i < (int)P.length();)
    {
        int idx = 0;
        int len = 0;
        for (int j = 0; j < (int)S.length(); j++)
        {
            int tmp = 0;
            while (P[i + tmp] == S[j + tmp])
                tmp++;
            if (len < tmp)
            {
                len = tmp;
                idx = j;
            }
        }
        i += len;
        ans++;
    }
    std::cout << ans << '\n';
}