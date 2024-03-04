#include <iostream>
#include <vector>
#include <algorithm>

int N, L;
std::vector< std::pair<int, int> > v;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int s, e;
		std::cin >> s >> e;
		v.push_back(std::make_pair(s, e));
	}
	std::sort(v.begin(), v.end());
	int cnt = 0;
	int last = 0;
	for (int i = 0; i < N; i++)
	{
		int s = v[i].first, e = v[i].second;
		if (last > s)
			s = last;
		if (s >= e)
			continue;
		if (last <= s)
		{
			cnt += (e - s - 1) / L + 1;
			last = s + ((e - s - 1) / L + 1) * L;
		}
	}
	std::cout << cnt << "\n";
}