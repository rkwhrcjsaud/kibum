#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

struct Node {
    int s, d, p, e;
};

int T, N;
int dp[10081];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        std::vector<Node> v[10081];
        for (int i = 0; i < N; i++)
        {
            Node tmp;
            std::cin >> tmp.s >> tmp.d >> tmp.p;
            tmp.e = tmp.s + tmp.d;
            v[tmp.e].push_back(tmp);
        }
        memset(dp, 0, sizeof(dp));
        int idx = 0;
        for (int i = 1; i <= 10080; i++) {
            dp[i] = dp[i - 1];
            for (int j = 0; j < v[i].size(); j++)
                dp[i] = std::max(dp[i], dp[v[i][j].s] + v[i][j].p);
        }
        std::cout << dp[10080] << '\n';
    }
}