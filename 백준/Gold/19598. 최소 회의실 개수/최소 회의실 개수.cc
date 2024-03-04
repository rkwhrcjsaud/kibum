#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector < std::pair< int, bool > > v;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int s, e;
		std::cin >> s >> e;
		v.push_back(std::make_pair(s, true));
		v.push_back(std::make_pair(e, false));
	}
	std::sort(v.begin(), v.end());
	int cnt = 1;
	int max = 1;
	for (int i = 1; i < N * 2; i++)
	{
		if (v[i].second)
			cnt++;
		else
			cnt--;
		if (max < cnt && (i == N * 2 - 1 || v[i].first != v[i + 1].first))
			max = cnt;
	}
	std::cout << max << "\n";
}