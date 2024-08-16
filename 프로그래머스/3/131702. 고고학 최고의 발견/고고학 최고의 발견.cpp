#include <string>
#include <vector>

using namespace std;
int N;

void rotate(int y, int x, vector<vector<int>> &tmp, int cnt)
{
    tmp[y][x] = (tmp[y][x] + cnt) % 4;
    if (y - 1 >= 0)
        tmp[y - 1][x] = (tmp[y - 1][x] + cnt) % 4;
    if (x - 1 >= 0)
        tmp[y][x - 1] = (tmp[y][x - 1] + cnt) % 4;
    if (x + 1 < N)
        tmp[y][x + 1] = (tmp[y][x + 1] + cnt) % 4;
    if (y + 1 < N)
        tmp[y + 1][x] = (tmp[y + 1][x] + cnt) % 4;
}

int solution(vector<vector<int>> clockHands) {
    int answer = 10000000;
    N = clockHands.size();
    for (int bit = 0; bit < (1 << (N * 2)); bit++) // 첫째줄이 돌아간 횟수
    {
        int total = 0;
        vector<vector<int>> tmp = clockHands;
        for (int i = 0; i < N; i++)
        {
            int cnt = 0;
            if (bit & (1 << (i * 2)))
                cnt += 1;
            if (bit & (1 << (i * 2 + 1)))
                cnt += 2;
            total += cnt;
            rotate(0, i, tmp, cnt);
        }
        
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // 바로 위칸이 12시 방향을 가르킬 때까지 회전
                if (tmp[i - 1][j] != 0)
                {
                    total += (4 - tmp[i - 1][j]);
                    rotate(i, j, tmp, 4 - tmp[i - 1][j]);
                }
            }
        }
        
        // 마지막 줄이 12시 방향을 가르키는지 확인
        bool clear = true;
        for (int i = 0; i < N; i++)
        {
            if (tmp[N - 1][i] != 0)
            {
                clear = false;
                break ;
            }
        }
        if (clear && answer > total)
            answer = total;
    }
    return answer;
}