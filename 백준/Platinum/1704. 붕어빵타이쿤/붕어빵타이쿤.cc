#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

int N, M;
bool arr[16][16];
std::vector<std::bitset<16 * 16> > v;

int compare(std::bitset<16 * 16> a, std::bitset<16 * 16> b)
{
    int cnta = a.count();
    int cntb = b.count();
    if (cnta == cntb)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (a.test(i * N + j) != b.test(i * N + j))
                    return a.test(i * N + j) < b.test(i * N + j);
            }
        }
    }
    return cnta < cntb;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> M >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            std::cin >> arr[i][j];
    for (int i = 0; i < (1 << N); i++)
    {
        int tmp[16][16];
        std::bitset<16 * 16> ans;
        ans.reset();
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                tmp[j][k] = arr[j][k];
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                ans.set(j);
                tmp[0][N - 1 - j] = !tmp[0][N - 1 - j];
                if (N - 1 - j > 0)
                    tmp[0][N - 1 - j - 1] = !tmp[0][N - 1 - j - 1];
                if (N - 1 - j < N - 1)
                    tmp[0][N - 1 - j + 1] = !tmp[0][N - 1 - j + 1];
                if (M > 1)
                    tmp[1][N - 1 - j] = !tmp[1][N - 1 - j];
            }
        }
        for (int j = 1; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (tmp[j - 1][k])
                {
                    tmp[j][k] = !tmp[j][k];
                    if (k > 0)
                        tmp[j][k - 1] = !tmp[j][k - 1];
                    if (k < N - 1)
                        tmp[j][k + 1] = !tmp[j][k + 1];
                    if (j < M - 1)
                        tmp[j + 1][k] = !tmp[j + 1][k];
                    ans.set(j * N + (N - k - 1));
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < N; j++)
        {
            if (tmp[M - 1][j])
            {
                flag = false;
                break ;
            }
        }
        if (flag)
            v.push_back(ans);
    }
    if (v.empty())
    {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }
    std::sort(v.begin(), v.end(), compare);
    for (int i = 0; i < M; i++)
    {
        for (int j = N - 1; j >= 0; j--)
            std::cout << v[0].test(i * N + j) << ' ';
        std::cout << '\n';
    }
}