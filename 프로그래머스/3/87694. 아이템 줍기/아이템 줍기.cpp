#include <string>
#include <vector>
#include <iostream>

using namespace std;
int line[102][102];
int CX, CY, IX, IY;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int posY, int posX)
{
    if (posY == IY && posX == IX)
        return 0;
    int ret = 100000000;
    line[posY][posX] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextY = posY + dir[i][0];
        int nextX = posX + dir[i][1];
        if (nextY < 0 || nextX < 0)
            continue ;
        if (!(line[nextY][nextX] & 1))
            continue ;
        ret = min(ret, dfs(nextY, nextX) + 1);
    }
    return ret;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            line[i][j] = 0;
    for (int i = 0; i < rectangle.size(); i++)
        for (int j = 0; j < rectangle[0].size(); j++)
            rectangle[i][j] *= 2;
    CX = characterX * 2;
    CY = characterY * 2;
    IX = itemX * 2;
    IY = itemY * 2;
    for (int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3];
        for (int j = y1; j <= y2; j++)
        {
            for (int k = x1; k <= x2; k++)
            {
                if ((j == y1 || j == y2 || k == x1 || k == x2) && line[j][k] != 2)
                    line[j][k] = 1;
                else
                    line[j][k] = 2;
            }
        }
    }
    return dfs(CY, CX) / 2;
}