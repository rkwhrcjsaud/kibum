#include <iostream>
#include <vector>
#include <algorithm>

int N, L, P;
std::vector< std::pair<int ,int> > v;
bool visited[10001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		std::cin >> a >> b;
		v.push_back(std::make_pair(a, b));
	}
	std::cin >> L >> P;
	std::sort(v.begin(), v.end());
	int pos = 0;
	int cnt = 0;
	if (P >= L)
	{
		std::cout << "0" << "\n";
		return 0;
	}
	while (1)
	{
		std::vector< std::pair<int, int> >::iterator iter = v.begin();
		std::vector< std::pair<int, int> >::iterator iter2 = iter;
		int max = 0;
		while (iter2 != v.end() && iter2->first <= P)
		{
			if (iter2->second > max && !visited[iter2 - v.begin()])
			{
				max = iter2->second;
				iter = iter2;
			}
			iter2++;
		}
		if (visited[iter - v.begin()])
			break ;
		visited[iter - v.begin()] = true;
		P += iter->second;
		if (P >= L)
		{
			std::cout << cnt + 1 << "\n";
			return 0;
		}
		cnt++;
	}
	std::cout << "-1" << "\n";
}