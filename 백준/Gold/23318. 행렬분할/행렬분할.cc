#include <iostream>

int N, M;
int a, b;
int map[20][8];
int min = 0x7fffffff;

void solve(int col, int row)
{
    int maxtmp = 0;
    for (int i = 0; i < N; i++)
    {
        int si = i;
        while (!(col & (1 << i)) && i < N - 1)
            i++;
        int ei = i;
        for (int j = 0; j < M; j++)
        {
            int sj = j;
            while (!(row & (1 << j)) && j < M - 1)
                j++;
            int ej = j;
            int tmp = map[ei][ej];
            if (si == 0)
            {
                if (sj == 0)
                    tmp -= 0;
                else
                    tmp -= map[ei][sj - 1];
            }
            else
            {
                if (sj == 0)
                    tmp -= map[si - 1][ej];
                else
                    tmp -= map[si - 1][ej] + map[ei][sj - 1] - map[si - 1][sj - 1];
            }
            maxtmp = std::max(maxtmp, tmp);
        }
    }
    min = std::min(min, maxtmp);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    std::cin >> a >> b;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> map[i][j];
            if (j != 0)
                map[i][j] += map[i][j - 1];
            if (i != 0)
                map[i][j] += map[i - 1][j];
            if (j != 0 && i != 0)
                map[i][j] -= map[i - 1][j - 1];
        }
    }
    for (int i = 0; i < (1 << (N - 1)); i++)
    {
        int tmp = i;
        int cnt = 0;
        while (tmp)
        {
            cnt += tmp & 1;
            tmp >>= 1;
        }
        if (cnt != a)
            continue ;
        for (int j = 0; j < (1 << (M - 1)); j++)
        {
            tmp = j;
            cnt = 0;
            while (tmp)
            {
                cnt += tmp & 1;
                tmp >>= 1;
            }
            if (cnt != b)
                continue ;
            solve(i, j);
        }
    }
    std::cout << min << '\n';
}