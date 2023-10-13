#include <iostream>
#include <deque>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
typedef long long ll;
int N, D;
ll arr[100001];
ll dp[100001];
ll ans;
std::deque < std::pair <ll, ll> > dq;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> D;
	int i = 1;
	ans = -1000000000;
	while (i <= N)
		std::cin >> arr[i++];
	i = 1;
	while (i <= N)
	{
		dp[i] = arr[i];
		while (!dq.empty() && dq.front().second < i - D)
		 	dq.pop_front();
		if (!dq.empty())
			dp[i] = MAX(dp[i], dq.front().first + arr[i]);
		while (!dq.empty() && dq.back().first < dp[i])
			dq.pop_back();
		dq.push_back(std::make_pair(dp[i], i));
		ans = MAX(ans, dp[i]);
		i++;
	}
	std::cout << ans << "\n";
}
