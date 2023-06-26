#include <iostream>
#include <queue>

int	main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);

	int	n;
	std::cin >> n;
	std::queue<int> queue;
	int	i = 1;
	while (i <= n)
		queue.push(i++);
	while (--n)
	{
		queue.pop();
		queue.push(queue.front());
		queue.pop();
	}
	std::cout << queue.front() << "\n";
}