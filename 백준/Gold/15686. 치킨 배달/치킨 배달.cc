#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int> > board;
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    board.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                house.push_back(make_pair(i, j));
            else if (board[i][j] == 2)
                chicken.push_back(make_pair(i, j));
        }
    }
    vector<int> v(chicken.size(), 0);
    for (int i = 0; i < M; i++)
        v[i] = 1;
    sort(v.begin(), v.end());
    int ans = 1e9;
    do
    {
        int sum = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int dist = 1e9;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (v[j] == 0)
                    continue;
                dist = min(dist, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
            }
            sum += dist;
        }
        ans = min(ans, sum);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << '\n';
}