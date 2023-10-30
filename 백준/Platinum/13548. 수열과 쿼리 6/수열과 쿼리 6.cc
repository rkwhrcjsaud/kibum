#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int N, M, root_N;
int arr[100001];
int ans[100001];
int visited[100001];
int cnt_table[100001];
#define MAX(a, b) (a > b ? a : b)

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
	int max = 0;
	while (i <= e)
	{
		cnt_table[visited[arr[i]]]--;
		visited[arr[i]]++;
		cnt_table[visited[arr[i]]]++;
		max = MAX(max, visited[arr[i]]);
		i++;
	}
	ans[q[1].idx] = max;
	i = 2;
	int left = s, right = e;
	while (i <= M)
	{
		s = q[i].s, e = q[i].e;
		int idx = q[i].idx;
		while (left > s)
		{
			left--;
			cnt_table[visited[arr[left]]]--;
			visited[arr[left]]++;
			max = MAX(max, visited[arr[left]]);
			cnt_table[visited[arr[left]]]++;
		}
		while (left < s)
		{
			cnt_table[visited[arr[left]]]--;
			if (max == visited[arr[left]] && cnt_table[visited[arr[left]]] == 0)
				max--;
			visited[arr[left]]--;
			cnt_table[visited[arr[left]]]++;
			left++;
		}
		while (right > e)
		{
			cnt_table[visited[arr[right]]]--;
			if (max == visited[arr[right]] && cnt_table[visited[arr[right]]] == 0)
				max--;
			visited[arr[right]]--;
			cnt_table[visited[arr[right]]]++;
			right--;
		}
		while (right < e)
		{
			right++;
			cnt_table[visited[arr[right]]]--;
			visited[arr[right]]++;
			max = MAX(max, visited[arr[right]]);
			cnt_table[visited[arr[right]]]++;
		}
		ans[idx] = max;
		i++;
	}
	i = 1;
	while (i <= M)
		std::cout << ans[i++] << "\n";
}