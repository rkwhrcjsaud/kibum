#include <iostream>
#include <vector>

int N, K;
std::vector< std::pair<int, std::vector<int> > > v;
std::vector< std::pair<int, std::vector<int> > > v2;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < 20; i++)
    {
        std::vector<int> tmp;
        for (int j = K; j < N + K; j++)
        {
            if (j & (1 << i))
                tmp.push_back(j - K + 1);
        }
        if (tmp.size())
            v.push_back(std::make_pair(1 << i, tmp));
    }
    for (int i = 0; i < v.size(); i++)
    {
        std::vector<int> tmp = v[i].second;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (tmp == v[j].second)
            {
                v[i].first |= v[j].first;
                v.erase(v.begin() + j--);
            }
        }
    }

    std::vector<int> a;
    for (int i = 0; i < N; i++)
        a.push_back(i + 1);
    v2.push_back(std::make_pair(K, a));
    for (int i = 0; i < 20; i++)
    {
        std::vector<int> tmp;
        for (int j = 0; j < N; j++)
        {
            if (j & (1 << i))
                tmp.push_back(j + 1);
        }
        if (tmp.size())
            v2.push_back(std::make_pair(1 << i, tmp));
    }
    for (int i = 0; i < v2.size(); i++)
    {
        std::vector<int> tmp = v2[i].second;
        for (int j = i + 1; j < v2.size(); j++)
        {
            if (tmp == v2[j].second)
            {
                v2[i].first |= v2[j].first;
                v2.erase(v2.begin() + j--);
            }
        }
    }
    if (v.size() < v2.size())
    {
        std::cout << v.size() << '\n';
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i].second.size() << ' ' << v[i].first << '\n';
            for (int j = 0; j < v[i].second.size(); j++)
            {
                std::cout << v[i].second[j] << ' ';
            }
            std::cout << '\n';
        }
    }
    else
    {
        std::cout << v2.size() << '\n';
        for (int i = 0; i < v2.size(); i++)
        {
            std::cout << v2[i].second.size() << ' ' << v2[i].first << '\n';
            for (int j = 0; j < v2[i].second.size(); j++)
            {
                std::cout << v2[i].second[j] << ' ';
            }
            std::cout << '\n';
        }
    }
}