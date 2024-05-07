#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
int arr[2010];
typedef long long ll;
ll dp[2010][2010];
ll JOI(int left, int right);

ll IOI(int left, int right)
{
    int left2 = (left + N - 1) % N;
    int right2 = (right + 1) % N;
    if (right2 == left)
        return 0;
    if (arr[left2] < arr[right2])
        return JOI(left, right2);
    return JOI(left2, right);
}

ll JOI(int left, int right)
{
    int left2 = (left + N - 1) % N;
    int right2 = (right + 1) % N;
    ll &ret = dp[left][right];
    if (ret != -1)
        return ret;
    if (right2 == left)
        return ret = 0;
    ret = std::max(
        arr[left2] + IOI(left2, right),
        arr[right2] + IOI(left, right2)
    );
    return ret;
}


int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 0; i < N; i++)
        ans = std::max(ans, arr[i] + IOI(i, i));
    std::cout << ans << '\n';
}