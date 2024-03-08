#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, K;
std::vector< std::vector<int> > v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> ans;
    for (int i = 0; i < 50; i++)
        ans.push_back(0);
    for (int i = 0; i < 36; i++)
        v.push_back(ans);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        while ((int)tmp.length() != 50)
            tmp = "-" + tmp;
        for (int j = 0; j < 50; j++)
        {
            if (tmp[j] == '-')
                continue ;
            if (std::isdigit(tmp[j]))
            {
                v[tmp[j] - '0'][j] += 35 - (tmp[j] - '0');
                ans[j] += (tmp[j] - '0');
            }
            else
            {
                v[tmp[j] - 'A' + 10][j] += 35 - (tmp[j] - 'A' + 10);
                ans[j] += (tmp[j] - 'A' + 10);
            }
        }
    }
    for (int i = 0; i < 36; i++)
    {
        for (int j = 49; j > 0; j--)
        {
            while (v[i][j] >= 36)
            {
                v[i][j] -= 36;
                v[i][j - 1]++;
            }
        }
    }
    std::cin >> K;
    std::sort(v.begin(), v.end(), std::greater< std::vector<int> >());
    for (int i = 0; i < K; i++)
        for (int j = 0; j < 50; j++)
            ans[j] += v[i][j];
    for (int i = 49; i > 0; i--)
    {
        while (ans[i] >= 36)
        {
            ans[i] -= 36;
            ans[i - 1]++;
        }
    }
    std::deque<int> q;
    int i = 0;
    while (ans[i] == 0)
        i++;
    for (; i < 50; i++)
        q.push_back(ans[i]);
    if (q.empty())
    {
        std::cout << "0\n";
        return 0;
    }
    while (q.front() >= 36)
    {
        q.push_front(q.front() / 36);
        q[1] = q[1] % 36;
    }
    while (!q.empty())
    {
        if (q.front() < 10)
            std::cout << (char)(q.front() + '0');
        else
            std::cout << (char)(q.front() - 10 + 'A');
        q.pop_front();
    }
    std::cout << '\n';
}