#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

int N, M;
class Drug {
    public:
        int r, b, d;
    Drug(int r, int b, int d) : r(r), b(b), d(d) {};
    ~Drug() {};
};
std::vector<Drug> v;
std::vector<std::pair<int, int> > ans;
int dp[51][51];

int compare(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < M; i++)
    {
        int r, b, d;
        std::cin >> r >> b >> d;
        for (int j = 50; j >= r; j--)
        {
            for (int k = 50; k >= b; k--)
            {
                if (dp[j - r][k - b] != -1)
                    dp[j][k] = std::max(dp[j][k], dp[j - r][k - b] + d);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        int r, b;
        std::cin >> r >> b;
        if (dp[r][b] == -1)
            ans.push_back(std::make_pair(i, 0));
        else
            ans.push_back(std::make_pair(i, dp[r][b]));
    }
    std::sort(ans.begin(), ans.end(), compare);
    for (int i = 0; i < ans.size(); i++)
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
}
