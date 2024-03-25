#include <iostream>
#include <queue>
#include <vector>

int N, M, K, ans;
int island[101];
std::vector<std::pair<int, int> > bridge[101];
bool visited[101][1 << 15];

int bitcnt(int n)
{
    int cnt = 0;
    while (n)
    {
        if (n & 1)
            cnt++;
        n >>= 1;
    }
    return cnt;
}

void solution()
{
    std::queue<std::pair<int, int> > q;
    q.push(std::make_pair(1, 0));
    visited[1][0] = true;
    if (island[1] != 0)
    {
        visited[1][1 << island[1]] = true;
        q.push(std::make_pair(1, 1 << island[1]));
    }
    while (!q.empty())
    {
        int cur = q.front().first;
        int curj = q.front().second;
        q.pop();
        int cntj = bitcnt(curj);
        if (cur == 1)
            ans = std::max(ans, cntj);
        for (int i = 0; i < bridge[cur].size(); i++)
        {
            int next = bridge[cur][i].first;
            int nextb = bridge[cur][i].second;
            int isj = island[next];
            if (cntj > nextb)
                continue ;
            if (!visited[next][curj])
            {
                visited[next][curj] = true;
                q.push(std::make_pair(next, curj));
            }
            if (isj != 0)
            {
                bool pick = curj & (1 << isj);
                if (!pick)
                {
                    int nextj = curj | (1 << isj);
                    if (!visited[next][nextj])
                    {
                        visited[next][nextj] = true;
                        q.push(std::make_pair(next, nextj));
                    }
                }
            }
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 1; i <= K; i++)
    {
        int tmp;
        std::cin >> tmp;
        island[tmp] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        bridge[a].push_back(std::make_pair(b, c));
        bridge[b].push_back(std::make_pair(a, c));
    }
    solution();
    std::cout << ans << '\n';
}