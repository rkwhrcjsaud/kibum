#include <iostream>
#include <vector>

int n;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	std::vector<int> v(n);
	int i = 0;
	while (i < n)
		std::cin >> v[i++];
	i = 0;
	int idx = 0;
	while (i < n)
	{
		std::cout << idx + 1 << "\n";
		int move = v[idx];
		v[idx] = 0;
		i++;
		if (i == n)
			break ;
		int k = 0;
		if (move > 0)
		{
			while (k < move)
			{
				idx = (++idx) % n;
				if (v[idx] == 0)
					continue ;
				k++;
			}
		}
		else
		{
			while (k > move)
			{
				idx = (idx + n - 1) % n;
				if (v[idx] == 0)
					continue ;
				k--;
			}
		}
	}
}