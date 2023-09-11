#include <iostream>
#include <vector>
#include <cstring>

#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)

int N, W;
std::vector < std::pair <int, int> > p1;
std::vector < std::pair <int, int> > p2;
int dp[1002][1002];

int	solve(int A, int B)
{
	if (A == W || B == W)
		return 0;
	if (dp[A][B] != -1)
		return (dp[A][B]);
	int next = MAX(A, B) + 1;
	int d1 = abs(p1[next].first - p1[A].first) + abs(p1[next].second - p1[A].second);
	int d2 = abs(p2[next].first - p2[B].first) + abs(p2[next].second - p2[B].second);
	int ans1 = solve(next, B) + d1;
	int ans2 = solve(A, next) + d2;
	dp[A][B] = MIN(ans1, ans2);
	return dp[A][B];
}

void	re(int A, int B)
{
	if (A == W || B == W)
		return ;
	int next = MAX(A, B) + 1;
	int d1 = abs(p1[next].first - p1[A].first) + abs(p1[next].second - p1[A].second);
	int d2 = abs(p2[next].first - p2[B].first) + abs(p2[next].second - p2[B].second);
	int ans1 = solve(next, B) + d1;
	int ans2 = solve(A, next) + d2;
	if (ans1 > ans2)
	{
		std::cout << 2 << "\n";
		re(A, next);
	}
	else
	{
		std::cout << 1 << "\n";
		re(next, B);
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> W;
	std::memset(dp, -1, sizeof(dp));
	int i = 0;
	p1.push_back(std::make_pair(1, 1));
	p2.push_back(std::make_pair(N, N));
	while (i++ < W)
	{
		int a, b;
		std::cin >> a >> b;
		p1.push_back(std::make_pair(a, b));
		p2.push_back(std::make_pair(a, b));
	}
	std::cout << solve(0, 0) << "\n";
	re(0, 0);
}