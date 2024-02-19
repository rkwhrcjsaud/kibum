#include <iostream>

int main(void)
{
    int T;
    std::cin >> T;
    if (T == 1)
    {
        long long a, b;
        std::cin >> a >> b;
        long long c = a + b;
        // str에 길이가 13이고 모든 문자를 a로 채운다.
        std::string str(13, 'a');
        // c를 26진수로 표현했을 때 각 자리가 지닌 수를 str의 각 자리에 더한다.
        for (int i = 12; i >= 0; i--)
        {
            str[i] += c % 26;
            c /= 26;
        }
        std::cout << str << std::endl;
    }
    else if (T == 2)
    {
        std::string str;
        std::cin >> str;
        long long c = 0;
        // str의 각 자리에 해당하는 수를 26진수로 표현했을 때 각 자리가 지닌 수를 c에 더한다.
        for (int i = 0; i < 13; i++)
        {
            c *= 26;
            c += str[i] - 'a';
        }
        std::cout << c << std::endl;
    }
}