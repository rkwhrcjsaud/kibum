#include <iostream>
#include <string>

typedef long long ll;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    while (1)
    {
        std::cin >> s;
        if (s == "#")
            break ;
        std::cout << s << " -> ";
        int total = 0;
        int n = 2;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            total += (s[i] - '0') * n;
            n++;
        }
        total %= 11;
        total = (11 - total);
        if (total == 10)
            std::cout << "Rejected\n";
        else if (total == 11)
            std::cout << "0\n";
        else
            std::cout << total << '\n';
    }
}