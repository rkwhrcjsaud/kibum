#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    int dp_max[3], dp_min[3];
    cin >> dp_max[0] >> dp_max[1] >> dp_max[2];
    dp_min[0] = dp_max[0];
    dp_min[1] = dp_max[1];
    dp_min[2] = dp_max[2];
    for (int i = 1; i < N; i++)
    {
        int tmp_max[3], tmp_min[3];
        cin >> tmp_max[0] >> tmp_max[1] >> tmp_max[2];
        tmp_min[0] = tmp_max[0];
        tmp_min[1] = tmp_max[1];
        tmp_min[2] = tmp_max[2];
        tmp_max[0] += max(dp_max[0], dp_max[1]);
        tmp_max[1] += max(dp_max[0], max(dp_max[1], dp_max[2]));
        tmp_max[2] += max(dp_max[1], dp_max[2]);
        tmp_min[0] += min(dp_min[0], dp_min[1]);
        tmp_min[1] += min(dp_min[0], min(dp_min[1], dp_min[2]));
        tmp_min[2] += min(dp_min[1], dp_min[2]);
        dp_max[0] = tmp_max[0];
        dp_max[1] = tmp_max[1];
        dp_max[2] = tmp_max[2];
        dp_min[0] = tmp_min[0];
        dp_min[1] = tmp_min[1];
        dp_min[2] = tmp_min[2];
    }
    cout << max(dp_max[0], max(dp_max[1], dp_max[2])) << ' ' << min(dp_min[0], min(dp_min[1], dp_min[2])) << '\n';
}