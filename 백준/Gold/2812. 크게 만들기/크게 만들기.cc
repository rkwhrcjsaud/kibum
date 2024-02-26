#include <iostream>
#include <deque>

int K, N;
std::string str;
std::deque<int> s;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> K >> N >> str;
    for (int i = 0; i < K; i++)
    {
        if (s.empty())
            s.push_back(str[i] - '0');
        else
        {
            while (N && !s.empty() && s.back() < str[i] - '0')
            {
                s.pop_back();
                N--;
            }
            s.push_back(str[i] - '0');
        }
    }
    while (N--)
        s.pop_back();
    for (std::deque<int>::iterator it = s.begin(); it != s.end(); it++)
        std::cout << *it;
    std::cout << '\n';
}