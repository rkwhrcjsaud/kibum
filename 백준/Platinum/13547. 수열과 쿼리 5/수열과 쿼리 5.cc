#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int N, M, root_N;
int arr[100001];
int visited[1000001];
int ans[100001];

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
	std::cin >> N;
	root_N = std::sqrt(N);
	int i = 1;
	while (i <= N)
		std::cin >> arr[i++];
	i = 0;
	std::cin >> M;
	while (++i <= M)
	{
		std::cin >> q[i].s >> q[i].e;
		q[i].idx = i;
	}
	std::sort(q + 1, q + M + 1, compare);
	int s = q[1].s, e = q[1].e;
	i = s;
	int temp = 0;
	while (i <= e)
	{
		visited[arr[i]]++;
		if (visited[arr[i]] == 1)
			temp++;
		i++;
	}
	ans[q[1].idx] = temp;
	i = 2;
	int left = s, right = e;
	while (i <= M)
	{
		s = q[i].s, e = q[i].e;
		int idx = q[i].idx;
		while (left > s)
			if (++visited[arr[--left]] == 1)
				temp++;
		while (left < s)
			if (--visited[arr[left++]] == 0)
				temp--;
		while (right > e)
			if (--visited[arr[right--]] == 0)
				temp--;
		while (right < e)
			if (++visited[arr[++right]] == 1)
				temp++;
		ans[idx] = temp;
		i++;
	}
	i = 1;
	while (i <= M)
		std::cout << ans[i++] << "\n";
}