#include <iostream>
#include <vector>

int n, max;
int	origin[1000002];
int ans[1000002];
std::vector<int> v;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 1;
	while (i <= n)
		std::cin >> origin[i++];
	i = n - 1;
	v.push_back(origin[n]);
	ans[n] = -1;
	while (i)
	{
		int temp = origin[i];
		while (v.size() && v.back() <= temp)
			v.pop_back();
		if (v.size())
			ans[i] = v.back();
		else
			ans[i] = -1;
		v.push_back(temp);
		i--;
	}
	i = 1;
	while (i <= n)
		std::cout << ans[i++] << " ";
}