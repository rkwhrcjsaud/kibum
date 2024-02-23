#include <iostream>
#include <vector>
#include <algorithm>

std::vector< std::pair<int, int> > oven;
std::vector<int> pizza;

// 바이너리 서치를 사용하여 pizza를 넣을 수 있는 가장 작은 오븐을 찾음
// oven은 first가 오븐의 지름, second가 같은 지름의 오븐의 개수
// oven은 내림차순으로 정렬되어 있으며 첫번째 인덱스에는 모든 피자를 넣을 수 있는 가장 큰 오븐이 있음
std::vector< std::pair<int, int> >::iterator find_oven(int pizza)
{
    std::vector< std::pair<int, int> >::iterator it = oven.begin();
    std::vector< std::pair<int, int> >::iterator end = oven.end();
    while (it != end)
    {
        std::vector< std::pair<int, int> >::iterator mid = it + (end - it) / 2;
        if (mid->first >= pizza)
            it = mid + 1;
        else
            end = mid;
    }
    return --it;
}


int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int D, N;
    std::cin >> D >> N;
    oven.push_back(std::make_pair(1000000001, 300001));
    for (int i = 0; i < D; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (oven.back().first <= tmp)
            oven.back().second++;
        else
            oven.push_back(std::make_pair(tmp, 1));
    }
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (!pizza.empty() && pizza.back() > tmp)
            tmp = pizza.back();
        pizza.push_back(tmp);
    }
    std::vector< std::pair<int, int> >::iterator last = oven.begin();
    for (std::vector<int>::iterator it = pizza.begin(); it != pizza.end(); it++)
    {
        std::vector< std::pair<int, int> >::iterator oven_it = find_oven(*it);
        // 찾은 오븐의 second가 0이면 더 큰 오븐을 대상으로 함
        while (oven_it->second == 0)
            oven_it--;
        oven_it->second--;
        last = oven_it;
    }
    // oven의 첫번째 원소의 second가 변동되었다면 0 출력
    if (oven.front().second != 300001)
    {
        std::cout << 0 << '\n';
        return 0;
    }
    // oven의 두번째 원소부터 시작하여 마지막으로 사용된 오븐의 second를 모두 합한 값을 출력
    int sum = 1;
    for (std::vector< std::pair<int, int> >::iterator it = oven.begin() + 1; it != last + 1; it++)
        sum += it->second;
    std::cout << sum << '\n';
}