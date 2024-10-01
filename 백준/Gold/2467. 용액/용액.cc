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
    int l = 0, r = N - 1;
    int minDiff = 2e9;
    int ans1, ans2;
    while (l < r)
    {
        int diff = v[l] + v[r];
        if (abs(diff) <= minDiff)
        {
            minDiff = abs(diff);
            ans1 = v[l];
            ans2 = v[r];
        }
        if (diff < 0)
            l++;
        else
            r--;
    }
    cout << ans1 << ' ' << ans2 << '\n';
}