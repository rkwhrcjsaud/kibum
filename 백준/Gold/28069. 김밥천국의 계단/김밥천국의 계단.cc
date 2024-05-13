#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, K;
bool visited[1000001];

void solve()
{
    std::queue< std::pair<int, int> > q;
    q.push(std::make_pair(0, 0));
    while (!q.empty())
    {
        int x = q.front().first;
        int k = q.front().second;
        q.pop();
        if (k > K || visited[x])
            continue ;
        if (x == N)
        {
            std::cout << "minigimbob\n";
            return ;
        }
        if (x + x / 2 <= N)
            q.push(std::make_pair(x + x / 2, k + 1));
        if (x + 1 <= N)
            q.push(std::make_pair(x + 1, k + 1));
        visited[x] = true;
    }
    std::cout << "water\n";
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    solve();
}
