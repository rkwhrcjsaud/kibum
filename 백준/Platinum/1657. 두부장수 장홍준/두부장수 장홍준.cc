#include <iostream>
#include <cstring>

#define MAX(a, b) (a > b ? a : b)
int N, M;
int dp[15 * 15 + 2][1 << 14];
int arr[15 * 15 + 2];
int grade[6][6] = 
{
	{0, 0, 0, 0, 0, 0},
	{0, 10, 8, 7, 5, 1},
	{0, 8, 6, 4, 3, 1},
	{0, 7, 4, 3, 2, 1},
	{0, 5, 3, 2, 2, 1},
	{0, 1, 1, 1, 1, 0},
};
int ans;

int solve(int pos, int bit)
{
	if (pos == N * M)
		return 0;
	if (dp[pos][bit] != -1)
		return dp[pos][bit];
	dp[pos][bit] = 0;
	dp[pos][bit] = MAX(dp[pos][bit], solve(pos + 1, bit >> 1));
	if (bit & 1)
		return dp[pos][bit] = MAX(dp[pos][bit], solve(pos + 1, bit >> 1));
	if (pos % M != M - 1 && !(bit & 2))
		dp[pos][bit] = MAX(dp[pos][bit], solve(pos + 2, bit >> 2) + grade[arr[pos]][arr[pos + 1]]);
	dp[pos][bit] = MAX(dp[pos][bit], solve(pos + 1, (bit >> 1) | (1 << (M - 1))) + grade[arr[pos]][arr[pos + M]]);
	return (dp[pos][bit]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	std::memset(dp, -1, sizeof(dp));
	int i = 0;
	while (i < N)
	{
		std::string tmp;
		std::cin >> tmp;
		int j = 0;
		while (j < M)
		{
			arr[i * M + j] = tmp[j] - 'A' - (tmp[j] == 'F') + 1;
			j++;
		}
		i++;
	}
	std::cout << solve(0, 0) << "\n";
}