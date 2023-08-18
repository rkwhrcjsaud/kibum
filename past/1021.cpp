#include <iostream>
#include <deque>

int	main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);

	int	n;
	std::cin >> n;
	std::deque<int> dq;
	int i = 1;
	while (i <= n)
		dq.push_back(i++);
	int m;
	std::cin >> m;
	int	ans = 0;
	while (m--)
	{
		int	temp;
		std::cin >> temp;
		i = 0;
		while (dq[i] != temp)
			i++;
		if (i <= dq.size() / 2)
		{
			while (i--)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
		}
		else
		{
			while (i++ < dq.size())
			{
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
		}
		dq.pop_front();
	}
	std::cout << ans << "\n";
}