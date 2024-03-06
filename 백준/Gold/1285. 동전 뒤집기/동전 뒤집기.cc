#include <iostream>

int N;
bool arr[21][21];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            std::cin >> c;
            arr[i][j] = (c == 'T');
        }
    }
    int min = 500;
    for (int i = 0; i < (1 << N); i++)
    {
        bool tmp[21][21];
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                tmp[j][k] = arr[j][k];
        for (int j = 0; j < N; j++)
        {
            if ((i >> j) & 1)
            {
                for (int k = 0; k < N; k++)
                    tmp[j][k] = !tmp[j][k];
            }
        }
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            int cntT = 0;
            int cntH = 0;
            for (int k = 0; k < N; k++)
            {
                if (tmp[k][j])
                    cntT++;
                else
                    cntH++;
            }
            if (cntT > cntH)
                cnt += cntH;
            else
                cnt += cntT;
        }
        if (cnt < min)
            min = cnt;
    }
    std::cout << min << '\n';
}