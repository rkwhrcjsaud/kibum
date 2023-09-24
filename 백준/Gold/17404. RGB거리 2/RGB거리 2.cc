#include <iostream>
#include <vector>

#define MIN(a, b) (a < b ? a : b)
#define INF 1000001

int dp[1001][3];
int N, ans;
std::vector < std::vector < int > > v;

std::vector <int> make_vector(int a, int b, int c)
{
	std::vector <int> temp;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(c);
	return (temp);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
	{
		int r, g, b;
		std::cin >> r >> g >> b;
		v.push_back(make_vector(r, g, b));
		i++;
	}
	i = 0;
	ans = INF;
	while (i < 3)
	{
		dp[0][i] = v[0][i];
		dp[0][(i + 1) % 3] = INF;
		dp[0][(i + 2) % 3] = INF;
		int j = 1;
		while (j < N)
		{
			dp[j][0] = v[j][0] + MIN(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = v[j][1] + MIN(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = v[j][2] + MIN(dp[j - 1][0], dp[j - 1][1]);
			j++;
		}
		ans = MIN(ans, MIN(dp[N - 1][(i + 1) % 3], dp[N - 1][(i + 2) % 3]));
		i++;
	}
	std::cout << ans << "\n";
}