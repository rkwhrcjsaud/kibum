#include <iostream>

int N;
std::string str;
std::string str1, str2, str3, str4;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    std::cin >> str;
    if (N % 2 == 0)
    {
        std::cout << "NOT POSSIBLE\n";
        return 0;
    }
    str1 = str.substr(0, N / 2);
    str2 = str.substr(N / 2);
    str3 = str.substr(0, (N + 1) / 2);
    str4 = str.substr((N + 1) / 2);
    int flag1 = true, flag2 = true;
    for (int i = 0, j = 0; i < N / 2; i++, j++)
    {
        if (str1[i] != str2[j])
        {
            if (i != j || (i == j && str1[i] != str2[j + 1]))
            {
                flag1 = false;
                break ;
            }
            else
                j++;
        }
    }
    for (int i = 0, j = 0; i < N / 2; i++, j++)
    {
        if (str3[j] != str4[i])
        {
            if (i != j || (i == j && str3[j + 1] != str4[i]))
            {
                flag2 = false;
                break ;
            }
            else
                j++;
        }
    }
    if (flag1 && flag2)
    {
        if (str1 == str4)
            std::cout << str1 << '\n';
        else
            std::cout << "NOT UNIQUE\n";
    }
    else if (flag1)
        std::cout << str1 << '\n';
    else if (flag2)
        std::cout << str4 << '\n';
    else
        std::cout << "NOT POSSIBLE\n";
}