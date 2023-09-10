#include <iostream>
#include <vector>

int N;
int cnt;
bool	arr[4000002];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 2;
	arr[1] = true;
	arr[0] = true;
	while (i * i <= N)
	{
		if (arr[i] == false)
		{
			int j = i * i;
			while (j <= N)
			{
				arr[j] = true;
				j += i;
			}
		}
		i++;
	}
	std::vector <long long> v;
	v.push_back(0);
	i = 2;
	while (i <= N)
	{
		if (arr[i] == false)
			v.push_back(v.back() + i);
		i++;
	}
	i = 1;
	int j = 1;
	int size = v.size();
	while (j <= size)
	{
		if (j >= i && v[j] - v[i - 1] >= N)
		{
			if (v[j] - v[i - 1] == N)
				cnt++;
			i++;
		}
		else
			j++;
	}
	std::cout << cnt << "\n";
}