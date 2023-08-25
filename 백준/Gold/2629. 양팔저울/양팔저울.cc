#include <iostream>

int n, m, sum;
int	arr[32];
bool	dp[32][15002];

void solve(int i, int j)
{
	if (i > n || dp[i][j])
		return ;
	dp[i][j] = true;
	solve(i + 1, j);
	solve(i + 1, j + arr[i]);
	solve(i + 1, abs(j - arr[i]));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		std::cin >> arr[i];
		sum += arr[i];
		i++;
	}
	std::cin >> m;
	solve(0, 0);
	i = 1;
	while (i <= m)
	{
		int temp;
		std::cin >> temp;
		if (temp > 15000)
			std::cout << "N ";
		else if (dp[n][temp])
			std::cout << "Y ";
		else
			std::cout << "N ";
		i++;
	}
}