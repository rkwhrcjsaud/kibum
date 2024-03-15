#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> mw;
std::vector<int> wm;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        std::cin >> t;
        if (t < 0)
            mw.push_back(t);
        else
            wm.push_back(t);
    }
    for (int i = 0; i < N; i++)
    {
        int t;
        std::cin >> t;
        if (t > 0)
            mw.push_back(t);
        else
            wm.push_back(t);
    }
    std::sort(mw.begin(), mw.end());
    std::sort(wm.begin(), wm.end());
    int ans = 0;
    int left = 0, right = mw.size() - 1;
    while (left < right && mw[left] < 0 && mw[right] > 0)
    {
        if (-1 * mw[left] > mw[right])
        {
            left++;
            right--;
            ans++;
        }
        else
        {
            right--;
        }
    }
    left = 0, right = wm.size() - 1;
    while (left < right && wm[left] < 0 && wm[right] > 0)
    {
        if (-1 * wm[left] > wm[right])
        {
            left++;
            right--;
            ans++;
        }
        else
        {
            right--;
        }
    }
    std::cout << ans << '\n';
}