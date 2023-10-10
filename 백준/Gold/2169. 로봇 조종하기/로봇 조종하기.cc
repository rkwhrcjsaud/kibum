#include <iostream>
#include <cstring>

#define MAX(a, b) (a > b ? a : b)
int N, M;
int arr[1002][1002];
int	dp[1002][1002];
int	temp[2][1002];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 1;
	while (i <= N)
	{
		int j = 1;
		while (j <= M)
			std::cin >> arr[i][j++];
		i++;
	}
	i = 1;
	while (i <= M)
	{
		dp[1][i] = dp[1][i - 1] + arr[1][i];
		i++;
	}
	i = 2;
	while (i <= N)
	{
		std::memset(temp, -100, sizeof(temp));
		int j = 1;
		while (j <= M)
		{
			temp[0][j] = MAX(dp[i - 1][j], temp[0][j - 1]) + arr[i][j];
			j++;
		}
		j = M;
		while (j > 0)
		{
			temp[1][j] = MAX(dp[i - 1][j], temp[1][j + 1]) + arr[i][j];
			dp[i][j] = MAX(temp[0][j], temp[1][j]);
			j--;
		}
		i++;
	}
	std::cout << dp[N][M] << "\n";
}