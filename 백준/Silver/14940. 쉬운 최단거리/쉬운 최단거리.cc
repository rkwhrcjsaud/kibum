#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int m[1001][1001];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int start_x, start_y;
int dp[1001][1001];

struct node
{
    int y, x, cnt;
    node(int _y, int _x, int _cnt) : y(_y), x(_x), cnt(_cnt) {};
};

struct cmp
{
    bool operator()(const node &a, const node &b) {
        return a.cnt > b.cnt;
    };
};

priority_queue<node, vector<node>, cmp> q;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 2)
            {
                start_y = i;
                start_x = j;
            }
        }
    }
    q.push(node(start_y, start_x, 0));
    dp[start_y][start_x] = 0;
    while (!q.empty())
    {
        int y = q.top().y;
        int x = q.top().x;
        int cnt = q.top().cnt;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            int ncnt = cnt + 1;
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue ;
            if (m[ny][nx] == 0)
                continue ;
            if (dp[ny][nx] == -1 || dp[ny][nx] > ncnt)
            {
                dp[ny][nx] = ncnt;
                q.push(node(ny, nx, ncnt));
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (m[i][j] == 0)
                cout << 0 << ' ';
            else
                cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}