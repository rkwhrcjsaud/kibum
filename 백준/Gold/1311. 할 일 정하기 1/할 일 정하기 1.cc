#include <iostream>
#include <cmath>

#define MIN(a, b) (a < b ? a : b)
#define INF 200001

short	D[22][22];
int		dp[1050000];
long long bit;
int N;

int count_bit(void)
{
	int cnt = 0;
	int i = 0;
	while (i < 20)
	{
		if ((bit >> i) & 1)
			cnt++;
		i++;
	}
	return cnt;
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
	i = 1;
	long long	temp = pow(2, N);
	while (i <= temp)
		dp[i++] = INF;
	while (bit < temp)
	{
		int x = count_bit();
		int j = 0;
		while (j < N)
		{
			if (((bit << j) & 1) == 0)
				dp[bit | (1 << j)] = MIN(dp[bit | (1 << j)], dp[bit] + D[x][j]);
			j++;
		}
		bit++;
	}
	std::cout << dp[temp - 1] << "\n";
}