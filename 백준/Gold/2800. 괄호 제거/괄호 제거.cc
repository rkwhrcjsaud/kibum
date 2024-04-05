#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::string str;
std::stack<int> s;
std::vector<std::pair<int, int> > v;
std::vector<std::string> ans;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s.push(i);
        else if (str[i] == ')')
        {
            v.push_back(std::make_pair(s.top(), i));
            s.pop();
        }
    }
    for (int i = 1; i < (1 << v.size()); i++)
    {
        std::string tmp = str;
        for (int j = 0; j < v.size(); j++)
        {
            if (i & (1 << j))
            {
                tmp[v[j].first] = ' ';
                tmp[v[j].second] = ' ';
            }
        }
        std::string res = "";
        for (int j = 0; j < tmp.size(); j++)
        {
            if (tmp[j] != ' ')
                res += tmp[j];
        }
        ans.push_back(res);
    }
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < ans.size(); i++)
        std::cout << ans[i] << '\n';
}