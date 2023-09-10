#include <iostream>
#include <vector>
#include <algorithm>

int N, C;
int arr[31];
std::vector <long long> v1;
std::vector <long long> v2; 

void	dfs2(int s, int e, long long sum)
{
	if (e < s)
		v2.push_back(sum);
	else
	{
		dfs2(s + 1, e, sum);
		dfs2(s + 1, e, sum + arr[s]);
	}
}

void	dfs1(int s, int e, long long sum)
{
	if (e < s)
		v1.push_back(sum);
	else
	{
		dfs1(s + 1, e, sum);
		dfs1(s + 1, e, sum + arr[s]);
	}
}

int compare(long long a, long long b)
{
	return (a < b);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> C;
	int i = 0;
	while (i < N)
		std::cin >> arr[i++];
	dfs1(0, N / 2 - 1, 0);
	dfs2(N / 2, N - 1, 0);
	std::sort(v2.begin(), v2.end(), compare);
	long long len = v1.size();
	long long cnt = 0;
	i = 0;
	while (i < len)
	{
		cnt += std::upper_bound(v2.begin(), v2.end(), C - v1[i]) - v2.begin();
		i++;
	}
	std::cout << cnt << "\n";
}