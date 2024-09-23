#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
vector<pair<int, int> > a;
vector<pair<int, int> > b;
vector<int> ans;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;;
    a.resize(N);
    for (int i = 0; i < N; i++)
    {
        a[i].second = i;
        cin >> a[i].first;
    }
    cin >> M;
    b.resize(M);
    for (int i = 0; i < M; i++)
    {
        b[i].second = i;
        cin >> b[i].first;
    }
    sort(a.begin(), a.end(), compare);
    sort(b.begin(), b.end(), compare);
    int idx_a = 0, idx_b = 0;
    int limit_a = 0, limit_b = 0;
    while (idx_a < N && idx_b < M)
    {
        if (a[idx_a].second < limit_a)
            idx_a++;
        else if (b[idx_b].second < limit_b)
            idx_b++;
        else if (a[idx_a].first == b[idx_b].first)
        {
            ans.push_back(a[idx_a].first);
            limit_a = a[idx_a].second;
            limit_b = b[idx_b].second;
            idx_a++;
            idx_b++;
        }
        else if (a[idx_a].first > b[idx_b].first)
            idx_a++;
        else if (a[idx_a].first < b[idx_b].first)
            idx_b++;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
