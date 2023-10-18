#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <queue>

typedef long long ll;
typedef std::pair <ll, ll> point;
int T, N, x, y;
std::vector < std::pair < point, int > > v;
std::vector < std::pair < point, int > > convex;
std::stack < std::pair < point, int > > s;
std::queue < std::pair < point, int > > q;

int compare(std::pair < point, int > a1, std::pair < point, int > b1)
{
	point a = a1.first;
	point b = b1.first;
	if (a.second < b.second)
		return 1;
	else if (a.second == b.second)
		return a.first < b.first;
	return 0;
}

ll ccw(point curr, point line1, point line2)
{
	return ((line2.first - line1.first) * (curr.second - line1.second)
			- (curr.first - line1.first) * (line2.second - line1.second));
}

ll dist1(point a, point b)
{
	return ((a.first - b.first) * (a.first - b.first)
			+ (a.second - b.second) * (a.second - b.second));
}

int compare2(std::pair < point, int > a1, std::pair < point, int > b1)
{
	point a = a1.first;
	point b = b1.first;
	ll cc = ccw(v[0].first, a, b);
	if (!cc)
		return (dist1(v[0].first, a) < dist1(v[0].first, b));
	return (cc > 0);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		v.clear();
		std::cin >> N;
		int i = 0;
		while (i < N)
		{
			std::cin >> x >> y;
			v.push_back(std::make_pair(std::make_pair(x, y), i));
			i++;
		}
		std::sort(v.begin(), v.end(), compare);
		std::sort(v.begin() + 1, v.end(), compare2);
		i = 0;
		int size = v.size();
		q.push(v[size - 1]);
		while (--size > 0)
		{
			if (ccw(v[size - 1].first, v[0].first, v[size].first) == 0)
				q.push(v[size - 1]);
			else
				break ;
		}
		while (i < size)
		{
			std::cout << v[i].second << " ";
			i++;
		}
		while (!q.empty())
		{
			std::cout << q.front().second << " ";
			q.pop();
		}
		std::cout << "\n";
	}
}