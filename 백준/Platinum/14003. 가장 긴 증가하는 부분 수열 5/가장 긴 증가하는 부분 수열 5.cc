#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int N;
std::vector <int> v1;
std::vector <int> v2;
std::vector <int> v3;
std::stack <int> s;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
	{
		int temp;
		std::cin >> temp;
		v1.push_back(temp);
		i++;
	}
	v2.push_back(v1[0]);
	i = 0;
	while (i < N)
	{
		int temp = std::lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
		if (temp != v2.size())
		{
			v2[temp] = v1[i];
			v3.push_back(temp + 1);
		}
		else
		{
			v2.push_back(v1[i]);
			v3.push_back(v2.size());
		}
		i++;
	}
	int max = v2.size();
	std::cout << max << "\n";
	i = N;
	while (--i >= 0)
	{
		if (max == v3[i])
		{
			s.push(v1[i]);
			max--;
		}
	}
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "\n";
}