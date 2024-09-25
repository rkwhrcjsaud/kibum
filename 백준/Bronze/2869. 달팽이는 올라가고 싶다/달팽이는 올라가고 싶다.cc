#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int A, B, V;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> A >> B >> V;
    int day = (V - B - 1) / (A - B) + 1;
    cout << day << '\n';
}