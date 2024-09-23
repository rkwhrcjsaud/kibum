#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
bool is_prime[1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    int cnt = 0;
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    for (int i = 2; i <= 1000; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * 2; j <= 1000; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (is_prime[num])
            cnt++;
    }
    cout << cnt << '\n';
}