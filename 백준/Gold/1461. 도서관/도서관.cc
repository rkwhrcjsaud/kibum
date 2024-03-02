#include <iostream>
#include <queue>
#include <cmath>

int N, M;
std::priority_queue<int> pluspq;
std::priority_queue<int, std::vector<int>, std::greater<int> > minuspq;
std::priority_queue<int> pq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (tmp > 0)
            pluspq.push(tmp);
        else
            minuspq.push(tmp);
    }
    while (!pluspq.empty())
    {
        pq.push(pluspq.top());
        for (int i = 0; i < M && !pluspq.empty(); i++)
            pluspq.pop();
    }
    while (!minuspq.empty())
    {
        pq.push(-minuspq.top());
        for (int i = 0; i < M && !minuspq.empty(); i++)
            minuspq.pop();
    }
    int result = pq.top();
    pq.pop();
    while (!pq.empty())
    {
        result += pq.top() * 2;
        pq.pop();
    }
    std::cout << result << '\n';
}
