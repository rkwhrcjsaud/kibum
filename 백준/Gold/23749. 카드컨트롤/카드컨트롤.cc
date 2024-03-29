#include <iostream>
#include <queue>

int N;
int bit;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
bool visited[1 << 10];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N * 2; i++)
    {
        char c;
        std::cin >> c;
        if (c == 'O')
            bit |= 1 << (N * 2 - i - 1);
    }
    pq.push(std::make_pair(0, bit));
    while (!pq.empty())
    {
        int top = pq.top().second;
        int cnt = pq.top().first;
        pq.pop();
        if (visited[top])
            continue ;
        visited[top] = true;
        int score = 0;
        for (int i = 0; i < N; i++)
        {
            if ((bool)(top & (1 << (2 * i))) == (bool)(top & (1 << (2 * i + 1))))
                continue ;
            if ((top & (1 << (2 * i + 1))))
                score++;
            else
                score--;
        }
        if (score > 0)
        {
            std::cout << cnt << '\n';
            return 0;
        }
        for (int i = 0; i < N * 2 - 1; i++)
        {
            int next = top & ((1 << i) - 1);
            next |= (top >> (1 + i)) << i;
            next |= ((top & (1 << i)) ? 1 : 0) << (N * 2 - 1);
            pq.push(std::make_pair(cnt + 1, next));
        }
    }
}