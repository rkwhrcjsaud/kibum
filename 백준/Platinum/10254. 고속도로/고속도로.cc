#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

typedef long long ll;
typedef std::pair <ll, ll> point;
int T, N, x, y;
std::vector < point > v;
std::vector < point > convex;
std::stack < point > s;
int left, right;

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

ll dist(point a, point b)
{
	return ((a.first - b.first) * (a.first - b.first)
			+ (a.second - b.second) * (a.second - b.second));
}

int compare2(point a, point b)
{
	ll c = ccw(v[0], a, b);
	if (!c)
		return (dist(v[0], a) < dist(v[0], b));
	return (c > 0);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		v.clear();
		convex.clear();
		while (!s.empty())
			s.pop();
		std::cin >> N;
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
		ll max_dist = 0;
		int max_point1 = 0, max_point2 = 1;
		i = 0;
		left = 0;
		right = 1;
		size = convex.size();
		while (left < size)
		{
			int left_next = (left + 1) % size;
			while (1)
			{
				int right_next = (right + 1) % size;
				point a, b;
				a.first = convex[left_next].first - convex[left].first;
				a.second = convex[left_next].second - convex[left].second;
				b.first = convex[right_next].first - convex[right].first;
				b.second = convex[right_next].second - convex[right].second;
				if (ccw(a, b, std::make_pair(0, 0)) < 0)
					right = right_next;
				else
					break ;
			}
			ll distance = dist(convex[left], convex[right]);
			if (distance > max_dist)
			{
				max_dist = distance;
				max_point1 = left;
				max_point2 = right;
			}
			left++;
		}
		std::cout << convex[max_point1].first << " " << convex[max_point1].second << " "
				<< convex[max_point2].first << " " << convex[max_point2].second << "\n";
	}
}