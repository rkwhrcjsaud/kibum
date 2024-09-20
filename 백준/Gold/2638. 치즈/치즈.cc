#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int> > board;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    board.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    vector<vector<int> > dist(N, vector<int>(M, 1e9));
    vector<vector<int> > visited(N, vector<int>(M, 0));
    dist[0][0] = 0;
    int ans = 0;
    while (!pq.empty())
    {
        int hereY = pq.top().second.first;
        int hereX = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();
        ans = max(ans, cost);
        if (dist[hereY][hereX] < cost)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int thereY = hereY + dir[i][0];
            int thereX = hereX + dir[i][1];
            if (thereY < 0 || thereY >= N || thereX < 0 || thereX >= M)
                continue;
            int nextDist = cost + board[thereY][thereX];
            visited[thereY][thereX]++;
            if (board[thereY][thereX] && visited[thereY][thereX] < 2)
                continue ;
            if (dist[thereY][thereX] > nextDist)
            {
                dist[thereY][thereX] = nextDist;
                pq.push(make_pair(-nextDist, make_pair(thereY, thereX)));
            }
        }
    }
    cout << ans << '\n';
}