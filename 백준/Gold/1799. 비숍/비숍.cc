#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;
vector<vector<int> > board;

int dfs(int y, int x, vector<pair<int, int> > &b)
{
    if (x >= N)
        x = (x % 2 == 0) ? 1 : 0, y++;
    if (y >= N)
        return (0);
    int ret = dfs(y, x + 2, b);
    if (board[y][x] == 0)
        return (ret);
    bool flag = true;
    for (int i = 0; i < b.size(); i++)
    {
        if (abs(b[i].first - y) == abs(b[i].second - x))
        {
            flag = false;
            break ;
        }
    }
    if (flag)
    {
        b.push_back(make_pair(y, x));
        ret = max(ret, dfs(y, x + 2, b) + 1);
        b.pop_back();
    }
    return (ret);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    vector<pair<int, int> > b;
    cout << dfs(0, 0, b) + dfs(0, 1, b) << '\n';
}