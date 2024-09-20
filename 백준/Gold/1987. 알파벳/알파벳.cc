#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
string board[21];

int dfs(int r, int c, int bit)
{
    int ret = 0;
    if (r < 0 || r >= R || c < 0 || c >= C)
        return 0;
    if (bit & (1 << (board[r][c] - 'A')))
        return 0;
    bit |= (1 << (board[r][c] - 'A'));
    ret = max(ret, dfs(r + 1, c, bit));
    ret = max(ret, dfs(r - 1, c, bit));
    ret = max(ret, dfs(r, c + 1, bit));
    ret = max(ret, dfs(r, c - 1, bit));
    return ret + 1;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> board[i];
    cout << dfs(0, 0, 0) << '\n';
}