#include <iostream>

int T;
bool visited[40][40];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
double dir[4];

double solution(int y, int x, int i)
{
    double percent = 0;
    if (i == T)
        return 1;
    for (int j = 0; j < 4; j++)
    {
        int ny = y + dy[j];
        int nx = x + dx[j];
        if (!visited[ny][nx])
        {
            visited[ny][nx] = true;
            percent += dir[j] * solution(ny, nx, i + 1);
            visited[ny][nx] = false;
        }
    }
    return percent;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T >> dir[0] >> dir[1] >> dir[2] >> dir[3];
    for (int i = 0; i < 4; i++)
        dir[i] /= 100;
    visited[20][20] = true;
    std::cout.precision(16);
    std::cout << solution(20, 20, 0) << "\n";
}