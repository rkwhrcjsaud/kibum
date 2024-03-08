#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int N;
long long visited[11];
bool isNotZero[11];
std::vector< std::pair<long long, bool> > v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string s;
        std::cin >> s;
        isNotZero[s[0] - 'A'] = true;
        for (int j = 0; j < (int)s.length(); j++)
            visited[s[j] - 'A'] += (long long)pow(10, (int)s.length() - j - 1);
    }
    for (int i = 0; i < 10; i++)
    {
        if (visited[i] == 0)
            continue ;
        v.push_back(std::make_pair(visited[i], isNotZero[i]));
    }
    std::sort(v.begin(), v.end());
    if (v.size() == 10)
    {
        int zeroidx = 0;
        for (int i = 0; i < 10; i++)
        {
            if (v[i].second == false)
            {
                zeroidx = i;
                break ;
            }
        }
        std::pair<long long, bool> tmp = v[zeroidx];
        for (int i = zeroidx; i > 0; i--)
            v[i] = v[i - 1];
        v[0] = tmp;
    }
    long long sum = 0;
    for (int i = 0; i < (int)v.size(); i++)
        sum += v[i].first * (9 - ((int)v.size() - i - 1));
    std::cout << sum << '\n';
}
