#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int a, b, c;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (cin >> a >> b >> c)
    {
        if (a == 0 && b == 0 && c == 0)
            break ;
        if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
            cout << "right\n";
        else
            cout << "wrong\n";
    }
}