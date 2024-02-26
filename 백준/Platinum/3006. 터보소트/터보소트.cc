#include <iostream>

int N;
int numidx[100010];
int tree[400010];

void update(int idx, int val)
{
    idx += 131071;
    tree[idx] = val;
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

int sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
    if (R < nodeL || nodeR < L)
        return 0;
    if (L <= nodeL && nodeR <= R)
        return tree[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        std::cin >> tmp;
        numidx[tmp] = i;
        update(i, 1);
    }
    int small = 1, big = N;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2)
        {
            std::cout << sum(1, numidx[small] - 1, 1, 1, 131071) << '\n';
            update(numidx[small], 0);
            small++;
        }
        else
        {
            std::cout << sum(numidx[big] + 1, N, 1, 1, 131071) << '\n';
            update(numidx[big], 0);
            big--;
        }
    }
}