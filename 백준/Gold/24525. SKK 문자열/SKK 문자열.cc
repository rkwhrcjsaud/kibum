#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

std::string str;
int kcnt[100001], scnt[100001];
int sum[100001];
int idx[300001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    int len = str.size();
    for (int i = 0; i < 300001; i++)
        idx[i] = 1e9;
    for (int i = 1; i <= len; i++)
    {
        sum[i] = sum[i - 1];
        kcnt[i] = kcnt[i - 1];
        scnt[i] = scnt[i - 1];
        if (str[i - 1] == 'S')
        {
            sum[i] += 2;
            scnt[i]++;
        }
        else if (str[i - 1] == 'K')
        {
            sum[i]--;
            kcnt[i]++;
        }
    }
    int ans = -1;
    for (int i = 0; i <= len; i++)
        idx[sum[i] + 100000] = std::min(idx[sum[i] + 100000], i);
    for (int i = 1; i <= len; i++)
    {
        int left = idx[sum[i] + 100000];
        if (left == 1e9)
            continue;
        int skk_len = i - left;
        int k_cnt = kcnt[i] - kcnt[left];
        int s_cnt = scnt[i] - scnt[left];
        if (k_cnt == 0 || s_cnt == 0)
            continue;
        ans = std::max(ans, skk_len);
    }
    std::cout << ans << '\n';
}