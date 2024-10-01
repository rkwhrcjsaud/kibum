#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;
typedef long long ll;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    vector<ll> lm, rm;
    vector<vector<int> > v(N, vector<int>(4));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 4; j++)
            cin >> v[i][j];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            lm.push_back((ll)v[i][0] + v[j][1]);
            rm.push_back((ll)v[i][2] + v[j][3]);
        }
    }
    sort(rm.begin(), rm.end());
    ll ans = 0;
    for (int i = 0; i < lm.size(); i++)
    {
        ll l = lm[i];
        ll r = upper_bound(rm.begin(), rm.end(), -l) - lower_bound(rm.begin(), rm.end(), -l);
        ans += r;
    }
    cout << ans << '\n';
}