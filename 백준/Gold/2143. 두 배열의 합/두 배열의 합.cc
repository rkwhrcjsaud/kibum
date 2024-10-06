#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int T, N, M;
vector<int> vn, vm;
vector<int> sn, sm;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> T;
    cin >> N;
    vn.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vn[i];
        if (i > 0)
            vn[i] += vn[i - 1];
        for (int j = 0; j <= i; j++)
            sn.push_back(vn[i] - (j == 0 ? 0 : vn[j - 1]));
    }
    cin >> M;
    vm.resize(M);
    for (int i = 0; i < M; i++)
    {
        cin >> vm[i];
        if (i > 0)
            vm[i] += vm[i - 1];
        for (int j = 0; j <= i; j++)
            sm.push_back(vm[i] - (j == 0 ? 0 : vm[j - 1]));
    }
    sort(sn.begin(), sn.end());
    sort(sm.begin(), sm.end());
    long long ans = 0;
    for (int i = 0; i < sn.size(); i++)
    {
        int target = T - sn[i];
        long long l = lower_bound(sm.begin(), sm.end(), target) - sm.begin();
        long long r = upper_bound(sm.begin(), sm.end(), target) - sm.begin();
        ans += r - l;
    }
    cout << ans << '\n';
}