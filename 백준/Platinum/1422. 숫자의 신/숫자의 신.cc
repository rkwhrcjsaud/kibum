#include <iostream>
#include <algorithm>
#include <vector>

int K, N;
std::vector<std::string> v;

int compare(std::string a, std::string b)
{
    return a + b > b + a;
}

bool comparemax(const std::string &a, const std::string &b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    return a > b;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> K >> N;
    std::string max;
    for (int i = 0; i < K; i++)
    {
        std::string s;
        std::cin >> s;
        v.push_back(s);
        if (comparemax(s, max))
            max = s;
    }
    for (int i = K; i < N; i++)
        v.push_back(max);
    std::sort(v.begin(), v.end(), compare);
    std::string str = "";
    for (int i = 0; i < N; i++)
        str = str + v[i];
    std::cout << str << '\n';
}
