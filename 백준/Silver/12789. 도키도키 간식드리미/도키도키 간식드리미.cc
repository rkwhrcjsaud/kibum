#include <iostream>
#include <stack>
#include <queue>

int n;
std::queue <int> start;
std::stack <int> mid;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	while (i++ < n)
	{
		int temp;
		std::cin >> temp;
		start.push(temp);
	}
	int current = 1;
	while (1)
	{
		if (start.empty() && mid.empty())
			break ;
		if (start.front() == current)
		{
			start.pop();
			current++;
		}
		else if (!mid.empty() && mid.top() == current)
		{
			mid.pop();
			current++;
		}
		else
		{
			mid.push(start.front());
			if (start.empty())
				break ;
			start.pop();
		}
	}
	if (start.empty() && mid.empty())
		std::cout << "Nice\n";
	else
		std::cout << "Sad\n";
}