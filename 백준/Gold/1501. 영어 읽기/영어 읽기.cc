#include <iostream>
#include <algorithm>
#include <map>

int N, M;
std::map<std::string, int> m;

int transform(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else
        return c - 'A' + 26;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        if (str.size() > 2)
        {
            std::string tmp = str.substr(1, str.size() - 2);
            std::sort(tmp.begin(), tmp.end());
            tmp = str[0] + tmp + str[str.size() - 1];
            m[tmp]++;
        }
        else
            m[str]++;
    }
    std::cin >> M;
    std::cin.ignore();
    for (int i = 0; i < M; i++)
    {
        int cnt = 1;
        std::string str;
        std::getline(std::cin, str);
        str = str + " ";
        for (int j = 0; j < (int)str.size(); j++)
        {
            if (str[j] == ' ')
            {
                std::string word = str.substr(0, j);
                if (word.size() > 2)
                {
                    std::string tmp = word.substr(1, word.size() - 2);
                    std::sort(tmp.begin(), tmp.end());
                    tmp = word[0] + tmp + word[word.size() - 1];
                    cnt *= m[tmp];
                }
                else
                    cnt *= m[word];
                str = str.substr(j + 1);
                j = 0;
            }
        }
        std::cout << cnt << '\n';
    }
}