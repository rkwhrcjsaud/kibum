#include <iostream>
#include <queue>

int N;
int parent[1010];
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
        int d, w;
        std::cin >> d >> w;
        pq.push(std::make_pair(w, d));
    }
    for (int i = 0; i <= 1000; i++)
        parent[i] = i;
    int total = 0;
    for (; !pq.empty(); pq.pop())
    {
        int d = pq.top().second;
        int w = pq.top().first;
        int x = union_find(d);
        if (x == 0)
            continue;
        union_merge(x, x - 1);
        total += w;
    }
    std::cout << total << '\n';
}
