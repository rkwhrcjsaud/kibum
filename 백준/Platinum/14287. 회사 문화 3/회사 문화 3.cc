#include <iostream>
#include <vector>

int N, M;

class node
{
	public :
		int start;
		int end;
		std::vector <int> next;
};

node arr[100001];
int tree[400004];

int dfs(int x, int num)
{
	int i = 0;
	int size = arr[x].next.size();
	arr[x].start = num;
	while (i < size)
	{
		int next = arr[x].next[i];
		num = dfs(next, num + 1);
		i++;
	}
	arr[x].end = num;
	return num;
}

void	add_seg(int s, int e, int n, int emp, int w)
{
	if (arr[emp].start > e || arr[emp].start < s)
		return ;
	tree[n] += w;
	if (s == e)
		return ;
	int mid = (s + e) / 2;
	add_seg(s, mid, n * 2, emp, w);
	add_seg(mid + 1, e, n * 2 + 1, emp, w);
}

int	search_w(int s, int e, int n, int emp)
{
	if (arr[emp].start > e || arr[emp].end < s)
		return 0;
	if (arr[emp].start <= s && arr[emp].end >= e)
		return tree[n];
	if (s == e)
		return 0;
	int mid = (s + e) / 2;
	return search_w(s, mid, n * 2, emp) + search_w(mid + 1, e, n * 2 + 1, emp);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int parent;
	std::cin >> parent;
	int i = 2;
	while (i <= N)
	{
		std::cin >> parent;
		arr[parent].next.push_back(i++);
	}
	dfs(1, 1);
	i = 1;
	while (i <= M)
	{
		int Q;
		std::cin >> Q;
		if (Q == 1)
		{
			int emp, w;
			std::cin >> emp >> w;
			add_seg(1, N, 1, emp, w);
		}
		else
		{
			int emp;
			std::cin >> emp;
			std::cout << search_w(1, N, 1, emp) << "\n";
		}
		i++;
	}
}