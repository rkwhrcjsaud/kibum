#include <iostream>

int N, M;
int arr[105][75];
bool visited[105][75];
int cnt;
int ispeak;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int solution(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (arr[ny][nx] > arr[y][x])
            ispeak = false;
        if (arr[ny][nx] == arr[y][x] && !visited[ny][nx])
            solution(ny, nx);
    }
    return 0;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 75; j++)
            arr[i][j] = -1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            std::cin >> arr[i][j];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (!visited[i][j])
            {
                ispeak = true;
                solution(i, j);
                cnt += ispeak;
            }
        }
    }
    std::cout << cnt << '\n';
}