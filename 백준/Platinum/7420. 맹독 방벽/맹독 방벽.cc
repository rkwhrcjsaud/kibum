#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cmath>

#define PI 3.1415926535
typedef long long ll;
typedef std::pair <ll, ll> point;
int N, x, y;
double L;
std::vector < point > v;
std::vector < point > convex;
std::stack < point > s;

int compare(point a, point b)
{
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

double dist(point a, point b)
{
	return (std::sqrt((a.first - b.first) * (a.first - b.first)
			+ (a.second - b.second) * (a.second - b.second)));
}

int compare2(point a, point b)
{
	ll c = ccw(v[0], a, b);
	if (!c)
		return (dist1(v[0], a) < dist1(v[0], b));
	return (c > 0);
}

double radian(point a, point b)
{
	return (std::acos((a.first * b.first + a.second * b.second)
		/ ((std::sqrt(a.first * a.first + a.second * a.second))
			* (std::sqrt(b.first * b.first + b.second * b.second)))));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> L;
	int i = 0;
	while (i < N)
	{
		std::cin >> x >> y;
		v.push_back(std::make_pair(x, y));
		i++;
	}
	std::sort(v.begin(), v.end(), compare);
	std::sort(v.begin() + 1, v.end(), compare2);
	s.push(v[0]);
	s.push(v[1]);
	i = 2;
	int size = v.size();
	point temp = v[0];
	while (i < size)
	{
		ll c = ccw(v[i], temp, s.top());
		if (c > 0)
		{
			temp = s.top();
			s.push(v[i]);
		}
		else if (c == 0)
		{
			s.pop();
			temp = s.top();
			s.push(v[i]);
		}
		else
		{
			s.pop();
			point temp2 = s.top();
			s.pop();
			temp = s.top();
			s.push(temp2);
			continue ;
		}
		i++;
	}
	i = 0;
	while (!s.empty())
	{
		convex.push_back(s.top());
		s.pop();
		i++;
	}
	i = 0;
	size = convex.size();
	double ans = 0;
	double rad = 0;
	if (size == 2)
	{
		ans += 2 * dist(convex[0], convex[1]);
		ans += 2 * L * PI;
	}
	else
	{
		while (i < size)
		{
			int i_next = (i + 1) % size;
			int i_prev = (size + i - 1) % size;
			ans += dist(convex[i], convex[i_next]);
			point a, b;
			a.first = convex[i_prev].first - convex[i].first;
			a.second = convex[i_prev].second - convex[i].second;
			b.first = convex[i_next].first - convex[i].first;
			b.second = convex[i_next].second - convex[i].second;
			rad = radian(a, b);
			ans += L * (PI - rad);
			i++;
		}
	}
	std::cout << std::fixed;
	std::cout.precision(0);
	std::cout << ans << "\n";
}