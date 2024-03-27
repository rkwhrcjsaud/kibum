#include <iostream>
#include <vector>
#include <algorithm>

int N;
int res;
std::vector<int> v;
std::vector<std::pair<int, int> > v1, v2;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    std::cin >> res;
    for (int i = 0; i < (1 << (N / 2)); i++)
    {
        int sum = 0;
        for (int j = 0; j < N / 2; j++)
        {
            if (i & (1 << j))
                sum += v[j];
        }
        if (sum > res)
            continue ;
        v1.push_back(std::make_pair(sum, i));
    }
    for (int i = 0; i < (1 << (N - N / 2)); i++)
    {
        int sum = 0;
        for (int j = 0; j < N - N / 2; j++)
        {
            if (i & (1 << j))
                sum += v[j + N / 2];
        }
        if (sum > res)
            continue ;
        v2.push_back(std::make_pair(sum, i));
    }
    std::sort(v1.begin(), v1.end());
    int ans = 0;
    for (int i = 0; i < v2.size(); i++)
    {
        int tmp = res - v2[i].first;
        int left = 0;
        int right = v1.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (v1[mid].first < tmp)
                left = mid + 1;
            else
                right = mid;
        }
        if (v1[left].first == tmp)
        {
            for (int j = 0; j < N / 2; j++)
                std::cout << (v1[left].second & (1 << j) ? 1 : 0);
            for (int j = 0; j < N - N / 2; j++)
                std::cout << (v2[i].second & (1 << j) ? 1 : 0);
            exit(0);
        }
    }
}