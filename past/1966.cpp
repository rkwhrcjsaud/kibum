#include <iostream>
#include <queue>

typedef struct	s_q
{
	int	num;
	int	flag;
}				t_q;

int	ismax(int n, std::queue<t_q *> queue)
{
	int	size = queue.size();
	int	max = 1;

	while (size--)
	{
		if (max < queue.front()->num)
			max = queue.front()->num;
		queue.push(queue.front());
		queue.pop();
	}
	if (max == n)
		return (1);
	return (0);
}

int	main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);

	int	l;
	std::cin >> l;
	std::queue<t_q *> queue;
	while (l--)
	{
		int	n, m, i;
		std::cin >> n;
		std::cin >> m;
		i = 1;
		while (n--)
		{
			t_q *temp = new t_q;
			std::cin >> temp->num;
			temp->flag = 0;
			if (m == 0)
				temp->flag = 1;
			m--;
			queue.push(temp);
		}
		while (1)
		{
			if (ismax(queue.front()->num, queue))
			{
				if (queue.front()->flag == 1)
				{
					std::cout << i << "\n";
					break ;
				}
				queue.pop();
				i++;
			}
			else
			{
				queue.push(queue.front());
				queue.pop();
			}
		}
		while (queue.size())
			queue.pop();
	}
}