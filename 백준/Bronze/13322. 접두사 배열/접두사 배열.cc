#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.size(); i++)
        std::cout << i << '\n';
}