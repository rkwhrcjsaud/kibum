#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;
ll N, T, root_N;
ll arr[100001];
ll visited[1000001];
ll ans[100001];

class Q
{
	public :
		int idx, s, e;
};

Q q[100001];

int compare(Q a, Q b)
{
	if (a.s / root_N < b.s / root_N)
		return 1;
	else if (a.s / root_N == b.s / root_N)
		return (a.e < b.e);
	return 0;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> T;
	root_N = std::sqrt(N);
	int i = 1;
	while (i <= N)
		std::cin >> arr[i++];
	i = 1;
	while (i <= T)
	{
		std::cin >> q[i].s >> q[i].e;
		q[i].idx = i;
		i++;
	}
	std::sort(q + 1, q + T + 1, compare);
	int s = q[1].s, e = q[1].e;
	i = s;
	ll temp = 0;
	while (i <= e)
	{
		visited[arr[i]]++;
		temp += (visited[arr[i]] * 2 - 1) * arr[i];
		i++;
	}
	ans[q[1].idx] = temp;
	i = 2;
	int left = s, right = e;
	while (i <= T)
	{
		s = q[i].s, e = q[i].e;
		int idx = q[i].idx;
		while (left > s)
		{
			left--;
			visited[arr[left]]++;
			temp += (visited[arr[left]] * 2 - 1) * arr[left];
		}
		while (left < s)
		{
			temp -= (visited[arr[left]] * 2 - 1) * arr[left];
			visited[arr[left]]--;
			left++;
		}
		while (right > e)
		{
			temp -= (visited[arr[right]] * 2 - 1) * arr[right];
			visited[arr[right]]--;
			right--;
		}
		while (right < e)
		{
			right++;
			visited[arr[right]]++;
			temp += (visited[arr[right]] * 2 - 1) * arr[right];
		}
		ans[idx] = temp;
		i++;
	}
	i = 1;
	while (i <= T)
		std::cout << ans[i++] << "\n";
}