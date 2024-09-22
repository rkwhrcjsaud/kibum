#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int A, B;
typedef long long ll;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> A >> B;
    int ans = 1;
    while (A < B)
    {
        if (B % 2 == 0)
            B /= 2;
        else if (B % 10 == 1)
            B /= 10;
        else
            break ;
        ans++;
    }
    if (A == B)
        cout << ans << '\n';
    else
        cout << "-1\n";
}