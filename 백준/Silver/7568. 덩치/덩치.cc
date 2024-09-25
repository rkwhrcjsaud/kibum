#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<pair<int, int> > v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    for (int i = 0; i < N; i++)
    {
        int cnt = 1;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue ;
            if (v[i].first < v[j].first && v[i].second < v[j].second)
                cnt++;
        }
        cout << cnt << ' ';
    }
}