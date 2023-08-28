#include <iostream>
#include <vector>

unsigned long long int n, cnt;
unsigned int origin[500002];
std::vector< std::pair< unsigned int, unsigned int > > v;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	unsigned int i = 1;
	while (i <= n)
		std::cin >> origin[i++];
	i = n - 1;
	v.push_back(std::make_pair(origin[n], 1));
	while (i)
	{
		unsigned int	temp = origin[i];
		unsigned int	temp2 = 1;
		while (v.size() && v.back().first <= temp)
		{
			if (v.back().first == temp)
				temp2 = v.back().second + 1;
			cnt += v.back().second;
			v.pop_back();
		}
		if (v.size())
			cnt++;
		v.push_back(std::make_pair(origin[i], temp2));
		i--;
	}
	std::cout << cnt << "\n";
}
