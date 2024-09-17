#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int T, K;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> K;
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int> > min_heap;
        map<int, int> cnt;
        for (int i = 0; i < K; i++)
        {
            char c;
            int n;
            cin >> c >> n;
            if (c == 'I')
            {
                max_heap.push(n);
                min_heap.push(n);
                cnt[n]++;
            }
            else if (c == 'D')
            {
                if (n == 1)
                {
                    while (!max_heap.empty() && cnt[max_heap.top()] == 0)
                        max_heap.pop();
                    if (!max_heap.empty())
                    {
                        cnt[max_heap.top()]--;
                        if (cnt[max_heap.top()] == 0)
                            max_heap.pop();
                    }
                }
                else if (n == -1)
                {
                    while (!min_heap.empty() && cnt[min_heap.top()] == 0)
                        min_heap.pop();
                    if (!min_heap.empty())
                    {
                        cnt[min_heap.top()]--;
                        if (cnt[min_heap.top()] == 0)
                            min_heap.pop();
                    }
                }
            }
        }
        while (!max_heap.empty() && cnt[max_heap.top()] == 0)
            max_heap.pop();
        while (!min_heap.empty() && cnt[min_heap.top()] == 0)
            min_heap.pop();
        if (max_heap.empty() || min_heap.empty())
            cout << "EMPTY" << '\n';
        else
            cout << max_heap.top() << ' ' << min_heap.top() << '\n';
    }
}