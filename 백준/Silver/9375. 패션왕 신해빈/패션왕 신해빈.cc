#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int T;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        map<string, int> m;
        for (int i = 0; i < N; i++)
        {
            string name, type;
            cin >> name >> type;
            m[type]++;
        }
        int ans = 1;
        for (auto it = m.begin(); it != m.end(); it++)
            ans *= (it->second + 1);
        cout << ans - 1 << '\n';
    }
}