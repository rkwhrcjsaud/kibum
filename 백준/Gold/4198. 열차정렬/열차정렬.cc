#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
int arr[2001];
int lis[2001];
int lds[2001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    std::vector<int> lisV;
    std::vector<int> ldsV;
    for (int i = 0; i < N; i++)
    {
        lisV.push_back(arr[i]);
        ldsV.push_back(arr[i]);
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] > lisV.back())
                lisV.push_back(arr[j]);
            else if (arr[j] > lisV.front())
            {
                std::vector<int>::iterator it = std::upper_bound(lisV.begin() + 1, lisV.end(), arr[j]);
                *it = arr[j];
            }
            if (arr[j] < ldsV.back())
                ldsV.push_back(arr[j]);
            else if (arr[j] < ldsV.front())
            {
                std::vector<int>::iterator it = std::upper_bound(ldsV.begin() + 1, ldsV.end(), arr[j], std::greater<int>());
                *it = arr[j];
            }
        }
        lis[i] = lisV.size();
        lds[i] = ldsV.size();
        lisV.clear();
        ldsV.clear();
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = std::max(ans, lis[i] + lds[i] - 1);
    std::cout << ans << '\n';
}
