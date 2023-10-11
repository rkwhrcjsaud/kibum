#include <iostream>
#include <cstring>

#define DIV 9901
typedef long long ll;
int N, M;
int dp[15 * 15][1 << 14];

int solve(int pos, int bit)
{
	if (pos == N * M)
		return (bit == 0);
	if (dp[pos][bit] != -1)
		return dp[pos][bit];
	dp[pos][bit] = 0;
	if (bit & 1)
		dp[pos][bit] += solve(pos + 1, bit >> 1);
	else
	{
		if (pos % M != M - 1 && !(bit & 2))
			dp[pos][bit] += solve(pos + 2, bit >> 2);
		dp[pos][bit] += solve(pos + 1, (bit >> 1) | (1 << (M - 1)));
	}
	return (dp[pos][bit] %= DIV);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	if (N % 2 == 1 && M % 2 == 1)
	{
		std::cout << "0\n";
		return 0;
	}
	std::memset(dp, -1, sizeof(dp));
	std::cout << solve(0, 0) << "\n";
}
