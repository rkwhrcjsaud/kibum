#include <iostream>
#include <deque>

int n, m;
bool	arr[100002];
std::deque < int > q;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	while (i < n)
		std::cin >> arr[i++];
	i = 0;
	while (i < n)
	{
		int temp;
		std::cin >> temp;
		if (arr[i])
		{
			i++;
			continue ;
		}
		q.push_back(temp);
		i++;
	}
	std::cin >> m;
	i = 0;
	int flag = q.size();
	while (i < m)
	{
		int temp;
		std::cin >> temp;
		if (!flag)
			std::cout << temp << " ";
		else
		{
			std::cout << q.back() << " ";
			q.push_front(temp);
			q.pop_back();
		}
		i++;
	}
}