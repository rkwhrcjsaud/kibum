#include <iostream>
#include <cmath>

#define MIN(a, b) (a < b ? a : b)
#define INF 16000001

int	D[16][16];
int	dp[16][100000];
long long bit;
int N;

int count_bit(void)
{
	int cnt = 0;
	int i = 0;
	while (i < 16)
	{
		if ((bit >> i) & 1)
			cnt++;
		i++;
	}
	return cnt;
}

int TSP(int now, int visited)
{
	if (visited == pow(2, N) - 1)
	{
		if (D[now][0] != 0)
			return D[now][0];
		return INF;
	}
	if (dp[now][visited] != 0)
		return dp[now][visited];
	dp[now][visited] = INF;
	int i = 0;
	while (i < N)
	{
		if (D[now][i] != 0 && (visited & (1 << i)) == 0)
		{
			int temp = TSP(i, visited | (1 << i));
			dp[now][visited] = MIN(dp[now][visited], D[now][i] + temp);
		}
		i++;
	}
	return dp[now][visited];
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
	{
		int j = 0;
		while (j < N)
			std::cin >> D[i][j++];
		i++;
	}
	std::cout << TSP(0, 1) << "\n";
}