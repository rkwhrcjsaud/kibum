#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> ans(3);
    long long minDiff = 3e9;
    for (int i = 1; i < N - 1; i++)
    {
        int l = 0, r = N - 1;
        while (r > i && l < i)
        {
            long long diff = (long long)v[l] + v[i] + v[r];
            if (std::abs(diff) <= minDiff)
            {
                minDiff = std::abs(diff);
                ans[0] = v[l];
                ans[1] = v[i];
                ans[2] = v[r];
            }
            if (diff < 0)
                l++;
            else
                r--;
        }
    }
    for (int i = 0; i < 3; i++)
        cout << ans[i] << ' ';
}