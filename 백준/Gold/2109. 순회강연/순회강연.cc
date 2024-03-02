#include <iostream>
#include <queue>

int N;
int parent[10010];
std::priority_queue<std::pair<int, int> > pq;

int union_find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = union_find(parent[x]);
}

void union_merge(int x, int y)
{
    x = union_find(x);
    y = union_find(y);
    if (x != y)
        parent[x] = y;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int p, d;
        std::cin >> p >> d;
        pq.push(std::make_pair(p, d));
    }
    for (int i = 0; i <= 10000; i++)
        parent[i] = i;
    int total = 0;
    for (; !pq.empty(); pq.pop())
    {
        int p = pq.top().first;
        int d = pq.top().second;
        int x = union_find(d);
        if (x == 0)
            continue;
        union_merge(x, x - 1);
        total += p;
    }
    std::cout << total << '\n';
}
