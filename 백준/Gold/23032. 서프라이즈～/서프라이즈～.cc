#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>

int N;
int arr[2001];
int sum[2001];
int diff = 1e9;
int size;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    for (int mid = 1; mid <= N - 1; mid++)
    {
        int left = mid;
        int right = mid + 1;
        while (left >= 1 && right <= N)
        {
            int left_sum = sum[mid] - sum[left - 1];
            int right_sum = sum[right] - sum[mid];
            if (diff > std::abs(left_sum - right_sum))
            {
                diff = std::abs(left_sum - right_sum);
                size = sum[right] - sum[left - 1];
            }
            else if (diff == std::abs(left_sum - right_sum))
                size = std::max(size, sum[right] - sum[left - 1]);
            if (left_sum > right_sum)
                right++;
            else
                left--;
        }
    }
    std::cout << size << '\n';
}