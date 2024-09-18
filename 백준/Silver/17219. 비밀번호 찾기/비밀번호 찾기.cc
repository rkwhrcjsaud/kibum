#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M;
map<string, string> m;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string site, password;
        cin >> site >> password;
        m[site] = password;
    }
    for (int i = 0; i < M; i++)
    {
        string site;
        cin >> site;
        cout << m[site] << '\n';
    }
}