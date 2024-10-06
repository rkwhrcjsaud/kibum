#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> v;
vector<vector<vector<int> > > dp;

int dfs(int left, int right, int idx)
{
    if (idx == v.size())
        return 0;
    if (dp[idx][left][right] != -1)
        return dp[idx][left][right];
    int &ret = dp[idx][left][right];
    ret = 1e9;
    if (left == 0 && right != v[idx])
        ret = min(ret, dfs(v[idx], right, idx + 1) + 2);
    if (right == 0 && left != v[idx])
        ret = min(ret, dfs(left, v[idx], idx + 1) + 2);
    if (left == v[idx])
        ret = min(ret, dfs(left, right, idx + 1) + 1);
    if (right == v[idx])
        ret = min(ret, dfs(left, right, idx + 1) + 1);
    if (left != v[idx] && right != v[idx])
    {
        if (abs(left - v[idx]) == 2)
            ret = min(ret, dfs(v[idx], right, idx + 1) + 4);
        else
            ret = min(ret, dfs(v[idx], right, idx + 1) + 3);
        if (abs(right - v[idx]) == 2)
            ret = min(ret, dfs(left, v[idx], idx + 1) + 4);
        else
            ret = min(ret, dfs(left, v[idx], idx + 1) + 3);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int tmp;
    while (cin >> tmp)
    {
        if (tmp == 0)
            break ;
        v.push_back(tmp);
    }
    dp.resize(v.size(), vector<vector<int> >(5, vector<int>(5, -1)));
    cout << dfs(0, 0, 0) << '\n';
}