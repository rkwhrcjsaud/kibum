#include <iostream>
#include <queue>
#include <vector>

int N, ans;
std::vector<std::string> word;
bool visited[16][1 << 16];

void solution()
{
    std::queue<std::pair<int ,int> > q;
    for (int i = 0; i < N; i++)
    {
        q.push(std::make_pair(i, 1 << i));
        visited[i][1 << i] = true;
    }
    while (!q.empty())
    {
        int idx = q.front().first;
        int bit = q.front().second;
        int last = word[idx][word[idx].size() - 1];
        q.pop();
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (bit & (1 << i))
                cnt += word[i].size();
        ans = std::max(ans, cnt);
        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i) || bit == (1 << N) - 1)
                continue ;
            if (last != word[i][0])
                continue ;
            if (visited[i][bit | (1 << i)])
                continue ;
            visited[i][bit | (1 << i)] = true;
            q.push(std::make_pair(i, bit | (1 << i)));
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        word.push_back(str);
    }
    solution();
    std::cout << ans << '\n';
}