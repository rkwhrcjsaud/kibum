#include <iostream>
#include <deque>

#define MAX(a, b) (a > b ? a : b)
typedef long long ll;
int N, K;
ll sum[100001];
ll dp[100001];
std::deque < std::pair <ll, ll> > dq;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> K;
	int i = 1;
	while (i <= N)
	{
		int tmp;
		std::cin >> tmp;
		sum[i] = sum[i - 1] + tmp;
		i++;
	}
	i = 1;
	while (i <= N)
	{
		while (!dq.empty() && dq.front().second < i - K)
			dq.pop_front();
		while (!dq.empty() && dq.back().first < dp[i - 1] - sum[i])
			dq.pop_back();
		dq.push_back(std::make_pair(dp[i - 1] - sum[i], i));
		dp[i] = sum[i] + dq.front().first;
		if (i <= K)
			dp[i] = MAX(dp[i], sum[i]);
		i++;
	}
	std::cout << dp[N] << "\n";
}
