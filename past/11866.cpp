#include <iostream>
#include <queue>
#include <string>

int	main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);

	int	n, k;
	std::cin >> n;
	std::cin >> k;
	std::queue<int> queue;
	int	i = 1;
	while (i <= n)
		queue.push(i++);
	int	s = n;
	std::string str;
	str = "<";
	while (s--)
	{
		int	j = 1;
		while (j < k)
		{
			queue.push(queue.front());
			queue.pop();
			j++;
		}
		str += std::to_string(queue.front());
		if (s != 0)
			str += ", ";
		queue.pop();
	}
	str += ">\n";
	std::cout << str;
}