#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

typedef long long ll;
int N;
typedef std::pair <ll, ll> point;
std::vector < point > v;
std::stack < std::pair <point, point> > s;

int compare(point a, point b)
{
	if (a.second < b.second)
		return 1;
	else if (a.second == b.second)
		return a.first < b.first;
	return 0;
}

ll ccw(point curr, std::pair < point, point > line)
{
	return ((line.second.first - line.first.first) * (curr.second - line.first.second)
			- (curr.first - line.first.first) * (line.second.second - line.first.second));
}

ll dist(point a, point b)
{
	return ((a.first - b.first) * (a.first - b.first)
			+ (a.second - b.second) * (a.second - b.second));
}

int compare2(point a, point b)
{
	ll c = ccw(v[0], std::make_pair(a, b));
	if (!c)
		return (dist(v[0], a) < dist(v[0], b));
	return (c > 0);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
	{
		int x, y;
		std::cin >> x >> y;
		v.push_back(std::make_pair(x, y));
		i++;
	}
	std::sort(v.begin(), v.end(), compare);
	std::sort(v.begin() + 1, v.end(), compare2);
	s.push(std::make_pair(v[0], v[1]));
	i = 2;
	int size = v.size();
	while (i < size)
	{
		ll c = ccw(v[i], s.top());
		if (c > 0)
			s.push(std::make_pair(s.top().second, v[i]));
		else if (c == 0)
		{
			std::pair <point, point> temp = s.top();
			s.pop();
			temp.second = v[i];
			s.push(temp);
		}
		else
		{
			s.pop();
			continue ;
		}
		i++;
	}
	std::cout << s.size() + 1 << "\n";
}