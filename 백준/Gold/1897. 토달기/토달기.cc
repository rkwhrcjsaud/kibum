#include <iostream>
#include <queue>
#include <vector>

int N;
std::queue<std::string> q;
std::vector<std::string> v[82];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str;
    std::cin >> N >> str;
    q.push(str);
    for (int i = 0; i < N; i++)
    {
        std::cin >> str;
        v[str.size()].push_back(str);
    }
    while (!q.empty())
    {
        std::string s = q.front();
        str = s;
        int size = s.size();
        q.pop();
        std::vector<std::string>::iterator it = v[size + 1].begin();
        for (; it != v[size + 1].end(); it++)
        {
            std::string tmp = *it;
            bool flag = false;
            for (int i = 0, j = 0; i < size; i++, j++)
            {
                if (s[i] != tmp[j])
                {
                    if (i != j || (i == j && s[i] != tmp[j + 1]))
                    {
                        flag = true;
                        break ;
                    }
                    else
                        j++;
                }
            }
            if (!flag)
                q.push(tmp);
        }
    }
    std::cout << str << '\n';
}