#include <iostream>
#include <vector>
#include <algorithm>

int X, Y;
typedef long long ll;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> X >> Y;
    int diff = Y - X;
    if (diff == 0)
    {
        std::cout << "0\n";
        return 0;
    }
    ll n = 1;
    while (n * n <= diff)
        n++;
    n--;
    int ans = 2 * n - 1;
    diff -= n * n;
    while (diff > 0)
    {
        for (int i = n; i > 0; i--)
        {
            if (diff >= i)
            {
                diff -= i;
                ans++;
                break ;
            }
        }
    }
    std::cout << ans << '\n';
}