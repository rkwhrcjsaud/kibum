#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
vector<int> dp[5][5][1 << 16];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int T = 0;

struct CardPair {
    int x1 = - 1, x2, y1, y2;
};

CardPair cardPair[7];
bool visited[7];


vector<int> move(int y, int x, int bit) // 카드가 bit처럼 존재할 때 x, y에서 모든곳에 대한 최소거리를 반환
{
    vector<int> &ret = dp[y][x][bit];
    if (!ret.empty())
        return ret;
    ret.resize(16, -1);
    ret[y * 4 + x] = 0;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(y, x, 0));
    while (!q.empty())
    {
        tuple<int, int, int>cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            tuple<int, int, int> next = cur;
            int &dy = get<0>(next) += dir[i][0];
            int &dx = get<1>(next) += dir[i][1];
            int &dist = ++get<2>(next);
            if (dy < 0 || dy >= 4 || dx < 0 || dx >= 4)
                continue ;
            if (ret[dy * 4 + dx] == -1)
            {
                ret[dy * 4 + dx] = dist;
                q.push(next);
            }
            if (bit & (1 << (dy * 4 + dx)))
                continue ;
            while (!(bit & (1 << (dy * 4 + dx))))
            {
                dy += dir[i][0];
                dx += dir[i][1];
                if (dy < 0 || dy >= 4 || dx < 0 || dx >= 4)
                {
                    dy -= dir[i][0];
                    dx -= dir[i][1];
                    break ;
                }
            }
            if (ret[dy * 4 + dx] != -1)
                continue ;
            ret[dy * 4 + dx] = dist;
            q.push(next);
        }
    }
    return ret;
}

int sol(int y, int x, int bit)
{
    if (bit == 0)
        return 0;
    int ret = 50000;
    vector<int> dist = move(y, x, bit);
    for (int i = 1; i <= T; i++)
    {
        if (visited[i])
            continue ;
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                int newbit = bit - (1 << (cardPair[i].y1 * 4 + cardPair[i].x1));
                int d = dist[cardPair[i].y1 * 4 + cardPair[i].x1] + 1; // i번 카드의 x1,y1을 먼저 엔터
                vector<int> dist2 = move(cardPair[i].y1, cardPair[i].x1, newbit);
                d += dist2[cardPair[i].y2 * 4 + cardPair[i].x2] + 1; // x2, y2로 가서 엔터
                newbit -= (1 << (cardPair[i].y2 * 4 + cardPair[i].x2));
                visited[i] = true;
                ret = min(ret, sol(cardPair[i].y2, cardPair[i].x2, newbit) + d);
                visited[i] = false;
            }
            else
            {
                int newbit = bit - (1 << (cardPair[i].y2 * 4 + cardPair[i].x2));
                int d = dist[cardPair[i].y2 * 4 + cardPair[i].x2] + 1; // i번 카드의 x2,y2을 먼저 엔터
                vector<int> dist2 = move(cardPair[i].y2, cardPair[i].x2, newbit);
                d += dist2[cardPair[i].y1 * 4 + cardPair[i].x1] + 1; // x1, y1로 가서 엔터
                newbit -= (1 << (cardPair[i].y1 * 4 + cardPair[i].x1));
                visited[i] = true;
                ret = min(ret, sol(cardPair[i].y1, cardPair[i].x1, newbit) + d);
                visited[i] = false;
            }
        }
    }
    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    int bit = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != 0)
            {
                T = max(T, board[i][j]);
                bit |= (1 << (i * 4 + j));
                if (cardPair[board[i][j]].x1 != -1)
                {
                    cardPair[board[i][j]].x2 = j;
                    cardPair[board[i][j]].y2 = i;
                }
                else
                {
                    cardPair[board[i][j]].x1 = j;
                    cardPair[board[i][j]].y1 = i;
                }
            }
        }
    }
    answer = sol(r, c, bit);
    return answer;
}