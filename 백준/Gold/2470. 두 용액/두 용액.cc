#include <iostream>
#include <vector>
#include <algorithm>

int n, min;
std::vector < int > v;

int compare(int a, int b)
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
	std::sort(v.begin(), v.end(), compare);
	min = 2000000001;
	int low = 0;
	int high = 0;
	int s = 0;
	int e = n - 1;
	while (s < e)
	{
		int temp = v[s] + v[e];
		if (min > abs(temp))
		{
			min = abs(temp);
			low = v[s];
			high = v[e];
		}
		if (temp >= 0)
			e--;
		else
			s++;
	}
	std::cout << low << " " << high << "\n";
}