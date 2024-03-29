#include <iostream>

int T, N, sum;
bool visited[1 << 20];
int arr[21];

bool solve(int bit, int len)
{
    if (bit == (1 << N) - 1)
        return true;
    if (visited[bit])
        return false;
    visited[bit] = true;
    for (int i = 0; i < N; i++)
    {
        if (bit & (1 << i))
            continue ;
        if (len + arr[i] > sum / 4)
            continue ;
        if (len + arr[i] == sum / 4)
        {
            if (solve(bit | (1 << i), 0))
                return true;
        }
        else
        {
            if (solve(bit | (1 << i), len + arr[i]))
                return true;
        }
    }
    return false;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        sum = 0;
        std::fill(arr, arr + 21, 0);
        std::fill(visited, visited + (1 << 20), false);
        for (int i = 0; i < N; i++)
        {
            std::cin >> arr[i];
            sum += arr[i];
        }
        if (sum % 4 == 0 && solve(0, 0))
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }
}