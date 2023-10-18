#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

typedef long long ll;
typedef std::pair <ll, ll> point;
int T, N, M, x, y;
std::vector < point > v_white;
std::vector < point > v_black;
std::vector < point > convex_w;
std::vector < point > convex_b;
std::stack < point > s;
point t;

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

int compare2(point a, point b)
{
	ll cc = ccw(t, a, b);
	if (!cc)
		return (dist1(t, a) < dist1(t, b));
	return (cc > 0);
}

void	make_convex(std::vector <point> &v, std::vector <point> &v2)
{
	std::sort(v.begin(), v.end(), compare);
	t = v[0];
	std::sort(v.begin() + 1, v.end(), compare2);
	s.push(v[0]);
	s.push(v[1]);
	int i = 2;
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
		v2.push_back(s.top());
		s.pop();
		i++;
	}
}

int check(point a, point b, point c, point d)
{
	ll temp1 = ccw(c, a, b) * ccw(d, a, b);
	ll temp2 = ccw(a, c, d) * ccw(b, c, d);
	if (temp1 == 0 && temp2 == 0)
	{
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);
		if (a <= d && b >= c)
			return 1;
		return (0);
	}
	else
	{
		if (temp1 <= 0 && temp2 <= 0)
			return 1;
		return 0;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		v_black.clear();
		v_white.clear();
		convex_b.clear();
		convex_w.clear();
		std::cin >> N >> M;
		int i = 0;
		while (i < N)
		{
			std::cin >> x >> y;
			v_black.push_back(std::make_pair(x, y));
			i++;
		}
		i = 0;
		while (i < M)
		{
			std::cin >> x >> y;
			v_white.push_back(std::make_pair(x, y));
			i++;
		}
		if (N > 2)
			make_convex(v_black, convex_b);
		else
			convex_b = v_black;
		if (M > 2)
			make_convex(v_white, convex_w);
		else
			convex_w = v_white;
		i = 0;
		int flag = 0;
		int size = convex_b.size();
		while (i < size && flag == 0)
		{
			int j = 0;
			int size2 = convex_w.size();
			while (j < size2 && size2 > 1)
			{
				int j_next = (j + 1) % size2;
				point i_next = std::make_pair(convex_b[i].first, 10001);
				if (check(convex_b[i], i_next, convex_w[j], convex_w[j_next]))
					flag++;
				j++;
			}
			if (flag == 1)
				break ;
			j = 0;
			flag = 0;
			while (j < size2 && size2 > 1)
			{
				int j_next = (j + 1) % size2;
				point i_prev = std::make_pair(convex_b[i].first, -1);
				if (check(convex_b[i], i_prev, convex_w[j], convex_w[j_next]))
					flag++;
				j++;
			}
			if (flag == 1)
				break ;
			flag = 0;
			j = 0;
			while (j < size2)
			{
				int j_next = (j + 1) % size2;
				if (check(convex_b[i], convex_b[(i + 1) % size], convex_w[j], convex_w[j_next]))
				{
					flag = 1;
					break ;
				}
				j++;
			}
			if (flag)
				break ;
			i++;
		}
		if (flag)
		{
			std::cout << "NO\n";
			continue ;
		}
		i = 0;
		size = convex_w.size();
		while (i < size)
		{
			int size2 = convex_b.size();
			int j = 0;
			while (j < size2 && size2 > 1)
			{
				int j_next = (j + 1) % size2;
				point i_next = std::make_pair(convex_w[i].first, 10001);
				if (check(convex_w[i], i_next, convex_b[j], convex_b[j_next]))
					flag++;
				j++;
			}
			if (flag == 1)
				break ;
			j = 0;
			flag = 0;
			while (j < size2 && size2 > 1)
			{
				int j_next = (j + 1) % size2;
				point i_prev = std::make_pair(convex_w[i].first, -1);
				if (check(convex_w[i], i_prev, convex_b[j], convex_b[j_next]))
					flag++;
				j++;
			}
			if (flag == 1)
				break ;
			flag = 0;
			i++;
		}
		if (flag)
			std::cout << "NO\n";
		else
			std::cout << "YES\n";
	}
}