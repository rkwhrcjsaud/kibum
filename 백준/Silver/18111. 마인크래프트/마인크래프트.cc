#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M, B;
vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M >> B;
    int minH = 1e9;
    int maxH = 0;
    v.resize(N * M);
    for (int i = 0; i < N * M; i++)
    {
        cin >> v[i];
        minH = min(minH, v[i]);
        maxH = max(maxH, v[i]);
    }
    int minTime = 1e9;
    int maxHeight = 0;
    for (int i = minH; i <= maxH; i++)
    {
        int add = 0;
        int remove = 0;
        for (int j = 0; j < N * M; j++)
        {
            if (v[j] < i)
                add += i - v[j];
            else
                remove += v[j] - i;
        }
        int tmp = remove * 2;
        if (add > remove + B)
            continue ;
        tmp += add;
        if (minTime >= tmp)
        {
            minTime = tmp;
            maxHeight = i;
        }
    }
    cout << minTime << ' ' << maxHeight << '\n';
}