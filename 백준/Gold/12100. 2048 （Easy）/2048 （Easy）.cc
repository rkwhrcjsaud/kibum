#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;
vector<vector<int> > v;
int ans = 0;

void dfs(int depth, vector<vector<int> > &board)
{
    if (depth == 5)
        return ;
    vector<vector<vector<int> > > tmp(4, vector<vector<int> >(board));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vector<int> v;
            for (int k = 0; k < N; k++)
            {
                if (i == 0)
                    v.push_back(board[k][j]);
                else if (i == 1)
                    v.push_back(board[j][N - k - 1]);
                else if (i == 2)
                    v.push_back(board[N - k - 1][j]);
                else
                    v.push_back(board[j][k]);
            }
            for (int k = 0; k < N; k++)
            {
                if (v[k] == 0)
                    continue ;
                for (int l = k + 1; l < N; l++)
                {
                    if (v[l] == 0)
                        continue ;
                    if (v[k] == v[l])
                    {
                        v[k] *= 2;
                        ans = max(ans, v[k]);
                        v[l] = 0;
                        break ;
                    }
                    else
                        break ;
                }
            }
            vector<int> tmp_v;
            for (int k = 0; k < N; k++)
            {
                if (v[k] != 0)
                    tmp_v.push_back(v[k]);
            }
            while (tmp_v.size() < N)
                tmp_v.push_back(0);
            for (int k = 0; k < N; k++)
            {
                if (i == 0)
                    board[k][j] = tmp_v[k];
                else if (i == 1)
                    board[j][N - k - 1] = tmp_v[k];
                else if (i == 2)
                    board[N - k - 1][j] = tmp_v[k];
                else
                    board[j][k] = tmp_v[k];
            }
        }
        dfs(depth + 1, board);
        board = tmp[i];
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
            ans = max(ans, v[i][j]);
        }
    }
    dfs(0, v);
    cout << ans << '\n';
}