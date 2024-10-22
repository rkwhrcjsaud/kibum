#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll N;

vector<vector<ll> > mult(const vector<vector<ll> > &a, const vector<vector<ll> > &b)
{
    vector<vector<ll> > ret(8, vector<ll>(8, 0));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    const vector<vector<ll> > road = {
        {0, 1, 1, 0, 0, 0, 0, 0}, // 정보과학관
        {1, 0, 1, 1, 0, 0, 0, 0}, // 전산관
        {1, 1, 0, 1, 1, 0, 0, 0}, // 미래관
        {0, 1, 1, 0, 1, 1, 0, 0}, // 신양관
        {0, 0, 1, 1, 0, 1, 0, 1}, // 한경직기념관
        {0, 0, 0, 1, 1, 0, 1, 0}, // 진리관
        {0, 0, 0, 0, 0, 1, 0, 1}, // 학생회관
        {0, 0, 0, 0, 1, 0, 1, 0}, // 형남공학관
    };
    vector<vector<ll> > ans(8, vector<ll>(8, 0));
    for (int i = 0; i < 8; i++)
        ans[i][i] = 1;
    vector<vector<ll> > temp = road;
    while (N)
    {
        if (N & 1)
            ans = mult(ans, temp);
        temp = mult(temp, temp);
        N >>= 1;
    }
    cout << ans[0][0] << '\n';
}