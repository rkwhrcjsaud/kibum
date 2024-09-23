#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<int> v(6);

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < 6; i++)
        cin >> v[i];
    int a, b;
    int cnt = 0;
    cin >> a >> b;
    for (int i = 0; i < 6; i++)
    {
        cnt += v[i] / a;
        if (v[i] % a == 0)
            continue ;
        cnt++;
    }
    cout << cnt << '\n';
    cout << N / b << ' ' << N % b << '\n';
}