#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N;
vector<int> arr;
int cnt[10] = {0, };

int sol(int start, int end, int cntp, int kind, int max)
{
    if (end >= N)
        return max;
    if (cnt[arr[end]] == 0) {
        kind++;
    }
    cntp++;
    cnt[arr[end]]++;
    if (kind > 2) {
        cnt[arr[start]]--;
        if (cnt[arr[start]] == 0)
            kind--;
        cntp--;
        start++;
    }
    if (cntp > max)
        max = cntp;
    return sol(start, end + 1, cntp, kind, max);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << sol(0, 0, 0, 0, 0) << '\n';
}