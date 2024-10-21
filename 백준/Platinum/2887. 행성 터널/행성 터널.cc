#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;
int parent[100001];

struct Planet
{
    int x, y, z, idx;
};

bool cmp_x(const Planet &a, const Planet &b)
{
    return a.x < b.x;
}

bool cmp_y(const Planet &a, const Planet &b)
{
    return a.y < b.y;
}

bool cmp_z(const Planet &a, const Planet &b)
{
    return a.z < b.z;
}

int union_find(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = union_find(parent[a]);
}

void union_merge(int a, int b)
{
    a = union_find(a);
    b = union_find(b);
    if (a != b)
        parent[a] = b;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    vector<Planet> v(N);
    vector<pair<int, pair<int, int> > > edge;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].x >> v[i].y >> v[i].z;
        v[i].idx = i;
        parent[i] = i;
    }
    sort(v.begin(), v.end(), cmp_x);
    for (int i = 0; i < N - 1; i++)
        edge.push_back(make_pair(abs(v[i].x - v[i + 1].x), make_pair(v[i].idx, v[i + 1].idx)));
    sort(v.begin(), v.end(), cmp_y);
    for (int i = 0; i < N - 1; i++)
        edge.push_back(make_pair(abs(v[i].y - v[i + 1].y), make_pair(v[i].idx, v[i + 1].idx)));
    sort(v.begin(), v.end(), cmp_z);
    for (int i = 0; i < N - 1; i++)
        edge.push_back(make_pair(abs(v[i].z - v[i + 1].z), make_pair(v[i].idx, v[i + 1].idx)));
    sort(edge.begin(), edge.end());
    int ans = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        if (union_find(a) != union_find(b))
        {
            union_merge(a, b);
            ans += edge[i].first;
        }
    }
    cout << ans << '\n';
}