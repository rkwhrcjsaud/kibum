#include <iostream>
#include <vector>
#include <algorithm>

int n, x, cnt;
std::vector <int> v;

int	compare(int a, int b)
{
	return (a < b);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		int temp;
		std::cin >> temp;
		v.push_back(temp);
		i++;
	}
	std::cin >> x;
	std::sort(v.begin(), v.end(), compare);
	int s = 0;
	int e = n - 1;
	while (s < e)
	{
		if (v[s] + v[e] == x)
		{
			s++;
			e--;
			cnt++;
		}
		else if (v[s] + v[e] < x)
			s++;
		else if (v[s] + v[e] > x)
			e--;
	}
	std::cout << cnt << "\n";
}