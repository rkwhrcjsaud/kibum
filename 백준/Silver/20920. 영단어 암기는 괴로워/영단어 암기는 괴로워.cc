#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int n, m;
std::map < std::string, int > map1;
std::vector < std::string > v;

int compare(std::string a, std::string b)
{
	if (a.size() == b.size() && map1[a] == map1[b])
		return a < b;
	else if (map1[a] == map1[b])
		return a.size() > b.size();
	return map1[a] > map1[b];
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	int i = 0;
	while (i < n)
	{
		std::string	temp;
		std::cin >> temp;
		if (temp.size() >= m)
		{
			if (map1.find(temp) == map1.end())
			{
				map1[temp] = 0;
				v.push_back(temp);
			}
			else
				map1[temp]++;
		}
		i++;
	}
	std::sort(v.begin(), v.end(), compare);
	i = 0;
	int len = v.size();
	while (i < len)
		std::cout << v[i++] << "\n";
}