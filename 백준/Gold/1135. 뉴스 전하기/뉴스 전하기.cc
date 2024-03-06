#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> v[51];

int dfs(int idx)
{
    if (v[idx].empty())
        return 0;
    std::vector<int> tmp;
    for (int i = 0; i < (int)v[idx].size(); i++)
        tmp.push_back(dfs(v[idx][i]));
    std::sort(tmp.begin(), tmp.end(), std::greater<int>());
    int ret = 0;
    for (int i = 0; i < (int)tmp.size(); i++)
        ret = std::max(ret, tmp[i] + i + 1);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    int tmp;
    std::cin >> tmp;
    for (int i = 1; i < N; i++)
    {
        std::cin >> tmp;
        v[tmp].push_back(i);
    }
    std::cout << dfs(0) << '\n';
}