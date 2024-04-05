#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::pair<std::string, std::string> arr[20] = {
    std::make_pair("a", "a"),
    std::make_pair("b", "b"),
    std::make_pair("c", "k"),
    std::make_pair("d", "d"),
    std::make_pair("e", "e"),
    std::make_pair("f", "g"),
    std::make_pair("g", "h"),
    std::make_pair("h", "i"),
    std::make_pair("i", "l"),
    std::make_pair("j", "m"),
    std::make_pair("k", "n"),
    std::make_pair("l", "ng"),
    std::make_pair("m", "o"),
    std::make_pair("n", "p"),
    std::make_pair("o", "r"),
    std::make_pair("p", "s"),
    std::make_pair("q", "t"),
    std::make_pair("r", "u"),
    std::make_pair("s", "w"),
    std::make_pair("t", "y"),
};

std::string str;
std::string str2;
std::vector<std::string> v;

std::string minToOrigin(std::string c)
{
    for (int i = 0; i < 20; i++)
    {
        if (arr[i].second == c)
            return arr[i].first;
    }
    return "";
}

std::string originToMin(std::string c)
{
    for (int i = 0; i < 20; i++)
    {
        if (arr[i].first == c)
            return arr[i].second;
    }
    return "";
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        str2 = "";
        std::cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'n' && j + 1 < str.size() && str[j + 1] == 'g')
            {
                str2 += minToOrigin("ng");
                j++;
            }
            else
                str2 += minToOrigin(std::string(1, str[j]));
        }
        v.push_back(str2);
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            std::cout << originToMin(std::string(1, v[i][j]));
        std::cout << '\n';
    }
}