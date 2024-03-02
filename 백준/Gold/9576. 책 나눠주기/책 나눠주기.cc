#include <iostream>
#include <vector>
#include <algorithm>

int T;

int union_find(int *parent, int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = union_find(parent, parent[a]);
}

void union_merge(int *parent, int a, int b)
{
    a = union_find(parent, a);
    b = union_find(parent, b);
    if (a != b)
        parent[a] = b;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        int N, M;
        std::cin >> N >> M;
        std::vector< std::pair<int, int> > v;
        int parent[1010] = {0, };
        for (int i = 1; i <= N + 1; i++)
            parent[i] = i;
        for (int i = 0; i < M; i++)
        {
            int a, b;
            std::cin >> a >> b;
            v.push_back(std::make_pair(b, a));
        }
        std::sort(v.begin(), v.end());
        int cnt = 0;
        for (std::vector< std::pair<int, int> >::iterator it = v.begin(); it != v.end(); it++)
        {
            int a = union_find(parent, it->second);
            if (a > it->first || a == 0)
                continue;
            union_merge(parent, a, a + 1);
            cnt++;
        }
        std::cout << cnt << '\n';
    }
}