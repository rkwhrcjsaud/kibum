#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, M, K;
vector<int> num;
vector<int> parent;

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
    {
        if (a > b)
            parent[b] = a;
        else
            parent[a] = b;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M >> K;
    num.resize(M);
    parent.resize(M);
    for (int i = 0; i < M; i++)
        cin >> num[i];
    sort(num.begin(), num.end());
    for (int i = 0; i < M; i++)
        parent[i] = i;
    for (int i = 0; i < K; i++)
    {
        int chulsu;
        cin >> chulsu;
        int idx = upper_bound(num.begin(), num.end(), chulsu) - num.begin();
        if (idx == M)
        {
            cout << num[union_find(0)] << '\n';
            union_merge(0, union_find(0) + 1);
        }
        else
        {
            cout << num[union_find(idx)] << '\n';
            union_merge(idx, union_find(idx) + 1);
        }
    }
}