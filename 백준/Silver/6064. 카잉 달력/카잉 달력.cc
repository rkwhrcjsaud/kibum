#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int T;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        int M, N;
        cin >> M >> N;
        int x, y;
        cin >> x >> y;
        int cnt = x;
        while (cnt % N != y % N)
        {
            cnt += M;
            if (cnt > M * N)
            {
                cnt = -1;
                break ;
            }
        }
        cout << cnt << '\n';
    }
}