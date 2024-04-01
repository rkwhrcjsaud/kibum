#include <iostream>
#include <vector>
#include <algorithm>

int N;
int max;
std::vector< std::pair<int, int> > v[5];
bool visited[20001];

void solve(int bit, int sum)
{
    if (bit == 31)
    {
        if (sum > max)
            max = sum;
        return ;
    }
    for (int i = 0; i < 5; i++)
    {
        if (bit & (1 << i))
            continue ;
        int tmp = 0;
        for (int j = 0; j < N; j++)
        {
            if (visited[v[i][j].second])
                continue ;
            visited[v[i][j].second] = true;
            solve(bit | (1 << i), sum + v[i][j].first + tmp);
            visited[v[i][j].second] = false;
            break ;
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
        for (int j = 0; j < 5; j++)
        {
            int tmp;
            std::cin >> tmp;
            v[j].push_back(std::make_pair(tmp, i));
        }
    }
    for (int i = 0; i < 5; i++)
        std::sort(v[i].begin(), v[i].end(), std::greater< std::pair<int, int> >());
    solve(0, 0);
    std::cout << max << '\n';
}