#include <iostream>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
std::priority_queue<int> distance;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, K;
	std::cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		std::cin >> tmp;
		pq.push(tmp);
	}
	int prev = pq.top();
	pq.pop();
	while (!pq.empty())
	{
		distance.push(pq.top() - prev);
		prev = pq.top();
		pq.pop();
	}
	while (--K && !distance.empty())
		distance.pop();
	int ans = 0;
	while (!distance.empty())
	{
		ans += distance.top();
		distance.pop();
	}
	std::cout << ans << '\n';
}
