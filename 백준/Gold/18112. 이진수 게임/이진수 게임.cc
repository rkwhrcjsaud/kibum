#include <iostream>
#include <queue>

int L, K;
int visited[1 << 16];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); i++)
    {
        L <<= 1;
        L |= str1[i] - '0';
    }
    for (int i = 0; i < str2.size(); i++)
    {
        K <<= 1;
        K |= str2[i] - '0';
    }
    std::fill(visited, visited + (1 << 16), -1);
    std::queue<int> q;
    q.push(L);
    visited[L] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == K)
        {
            std::cout << visited[cur] << '\n';
            return 0;
        }
        for (int i = 1; (1 << (i + 1)) <= cur; i++)
        {
            if (visited[cur ^ (1 << i)] == -1)
            {
                visited[cur ^ (1 << i)] = visited[cur] + 1;
                q.push(cur ^ (1 << i));
            }
        }
        if (cur != 0 && visited[cur - 1] == -1)
        {
            visited[cur - 1] = visited[cur] + 1;
            q.push(cur - 1);
        }
        if (cur != (1 << 16) - 1 && visited[cur + 1] == -1)
        {
            visited[cur + 1] = visited[cur] + 1;
            q.push(cur + 1);
        }
    }
}