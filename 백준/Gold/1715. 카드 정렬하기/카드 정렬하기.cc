#include <iostream>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

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
		pq.push(tmp);
	}
	int ans = 0;
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	std::cout << ans << '\n';
}
