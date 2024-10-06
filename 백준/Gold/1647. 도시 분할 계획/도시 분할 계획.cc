#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
struct edge
{
    int a, b, c;
    edge(int a, int b, int c) : a(a), b(b), c(c) {}
};

vector<edge> v;
vector<int> parent;

bool cmp(edge &a, edge &b)
{
    return a.c < b.c;
}

int union_find(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = union_find(parent[a]);
}

void union_set(int a, int b)
{
    a = union_find(a);
    b = union_find(b);
    if (a != b)
        parent[b] = a;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(edge(a, b, c));
    }
    sort(v.begin(), v.end(), cmp);
    int sum = 0;
    int last = 0;
    for (int i = 0; i < M; i++)
    {
        if (union_find(v[i].a) != union_find(v[i].b))
        {
            union_set(v[i].a, v[i].b);
            sum += v[i].c;
            last = v[i].c;
        }
    }
    cout << sum - last << '\n';
}