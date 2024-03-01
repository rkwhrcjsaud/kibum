#include <iostream>
#include <queue>

std::priority_queue<int> pluspq;
std::priority_queue<int, std::vector<int>, std::greater<int> > minuspq;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp > 0)
			pluspq.push(tmp);
		else
			minuspq.push(tmp);
	}
	int ans = 0;
	while (pluspq.size() > 1)
	{
		int a = pluspq.top();
		pluspq.pop();
		int b = pluspq.top();
		pluspq.pop();
		if (a == 1 || b == 1)
			ans += a + b;
		else
			ans += a * b;
	}
	if (pluspq.size())
		ans += pluspq.top();
	while (minuspq.size() > 1)
	{
		int a = minuspq.top();
		minuspq.pop();
		int b = minuspq.top();
		minuspq.pop();
		ans += a * b;
	}
	if (minuspq.size())
		ans += minuspq.top();
	std::cout << ans << '\n';
}
