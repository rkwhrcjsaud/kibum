#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    int cnt = 1;
    int sum = 1;
    while (sum < N)
    {
        sum += 6 * cnt;
        cnt++;
    }
    cout << cnt << '\n';
}