#include <iostream>
#include <vector>
#include <deque>

int N, L;
std::deque < std::pair <int, int> > dq;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> L;
	int i = 0;
	while (i < N)
	{
		int tmp;
		std::cin >> tmp;
		if (!dq.empty() && dq.front().second < i - L + 1)
			dq.pop_front();
		while (!dq.empty() && dq.back().first > tmp)
			dq.pop_back();
		dq.push_back(std::make_pair(tmp, i));
		std::cout << dq.front().first << " ";
		i++;
	}
}