#include <iostream>
#include <stack>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

int N;
int arr[1002];
int dp[1002];
int ans[1002];
int max;
std::stack <int> s;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
		std::cin >> arr[i++];
	max = 1;
	i = 1;
	while (i <= N)
	{
		int j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = MAX(dp[i], dp[j] + 1);
				max = MAX(max, dp[i]);
			}
			j++;
		}
		i++;
	}
	std::cout << max << "\n";
	i = max;
	while (N)
	{
		if (dp[N] == i)
		{
			s.push(arr[N]);
			break ;
		}
		N--;
	}
	int cur = N;
	i = N - 1;
	while (i)
	{
		if (s.top() > arr[i] && dp[i] + 1 == dp[cur])
		{
			cur = i;
			s.push(arr[i]);
		}
		i--;
	}
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "\n";
}