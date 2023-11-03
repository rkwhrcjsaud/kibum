#include <iostream>

std::string str[5];

int main(void)
{
    int i = 0;
    while (i < 5)
        std::cin >> str[i++];
    i = 0;
    while (i < 15)
    {
        int j = 0;
        while (j < 5)
        {
            if (str[j].size() > i)
                std::cout << str[j][i];
            j++;
        }
        i++;
    }
    std::cout << "\n";
}