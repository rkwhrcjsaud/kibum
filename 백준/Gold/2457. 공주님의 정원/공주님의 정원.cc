#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector< std::pair<int, int> > flower;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int startM, startD, endM, endD;
        std::cin >> startM >> startD >> endM >> endD;
        flower.push_back(std::make_pair(startM * 100 + startD, endM * 100 + endD));
    }
    std::sort(flower.begin(), flower.end());
    int start = 301;
    int end = 301;
    int cnt = 0;
    for (std::vector< std::pair<int, int> >::iterator it = flower.begin(); it != flower.end(); it++)
    {
        if (it->first > end)
        {
            std::cout << "0\n";
            return 0;
        }
        if (it->first > start)
        {
            start = end;
            cnt++;
        }
        if (it->second > end)
            end = it->second;
        if (end >= 1201)
        {
            std::cout << cnt + 1 << '\n';
            return 0;
        }
    }
    std::cout << "0\n";
}