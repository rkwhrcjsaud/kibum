#include <iostream>
#include <vector>
#include <set>

#define MAX(a, b) (a > b ? a : b)

int N;
typedef long long ll;
std::vector < std::pair < std::pair <ll, ll>, std::pair <ll, ll> > > v;
std::vector < int > group[3002];
std::set <int> s;
int parent[3002];

int ccw(std::pair <ll, ll> a, std::pair <ll, ll> b, std::pair <ll, ll> c)
{
	ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
	temp -= b.first * a.second + c.first * b.second + a.first * c.second;
	if (temp > 0)
		return 1;
	else if (temp == 0)
		return 0;
	return (-1);
}

int check(std::pair < std::pair <ll, ll>, std::pair <ll, ll> > a,
	std::pair < std::pair <ll, ll>, std::pair <ll, ll> > b)
{
	std::pair <ll, ll> A = a.first;
	std::pair <ll, ll> B = a.second;
	std::pair <ll, ll> C = b.first;
	std::pair <ll, ll> D = b.second;
	int temp1 = ccw(A, B, C) * ccw(A, B, D);
	int temp2 = ccw(C, D, A) * ccw(C, D, B);
	if (temp1 == 0 && temp2 == 0)
	{
		if (A > B)
			swap(A, B);
		if (C > D)
			swap(C, D);
		if (A <= D && B >= C)
			return (1);
		return (0);
	}
	else if (temp1 <= 0 && temp2 <= 0)
		return (1);
	return (0);
}

int find_root(int x)
{
	if (x != parent[x])
		return (parent[x] = find_root(parent[x]));
	return (parent[x]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int max = 0;
	int i = 0;
	while (++i <= N)
		parent[i] = i;
	i = 0;
	while (i < N)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		std::pair < std::pair <ll, ll>, std::pair <ll, ll> > temp
			= std::make_pair(std::make_pair(a, b), std::make_pair(c, d));
		int j = 0;
		int size = v.size();
		while (j < size)
		{
			if (check(v[j], temp) && parent[i] != find_root(j))
				parent[find_root(j)] = i;
			j++;
		}
		v.push_back(temp);
		i++;
	}
	i = 0;
	while (i < N)
	{
		int j = 0;
		int cnt = 0;
		while (j < N)
		{
			if (find_root(i) == find_root(j))
				cnt++;
			j++;
		}
		max = MAX(max, cnt);
		s.insert(find_root(i));
		i++;
	}
	std::cout << s.size() << "\n";
	std::cout << max << "\n";
}