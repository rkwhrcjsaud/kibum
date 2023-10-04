#include <iostream>
#include <vector>

typedef long long ll;
int N;
ll	arr[500001];
ll	ans;

void	merge(int s, int mid, int e)
{
	std::vector <ll> v;
	int i = s;
	int j = mid + 1;
	int k = e;
	while (i <= mid && j <= e)
	{
		if (arr[i]<=arr[j])
			v.push_back(arr[i++]);
		else
		{
			ans += mid - i + 1;
			v.push_back(arr[j++]);
		}
	}
	if (i > mid)
	{
		while(j <= e)
			v.push_back(arr[j++]);
	}
	else
	{
		while(i <= mid)
			v.push_back(arr[i++]);
	}
	i = 0;
	while (s <= e)
		arr[s++] = v[i++];
}

void	make_tree(int s, int e)
{
	if (s < e)
	{
		int mid = (s + e) / 2;
		make_tree(s, mid);
		make_tree(mid + 1, e);
		merge(s, mid, e);
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
		std::cin >> arr[i++];
	make_tree(1, N);
	std::cout << ans << "\n";
}