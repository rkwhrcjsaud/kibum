#include <iostream>
#include <vector>
#include <stack>

#define MIN(a, b) (a < b ? a : b)
#define INF 10000000
int N, M;
int SRC, SINK;
int out = 10000;
char arr[10010];
std::vector <int> v[20010];
int c[20010][11];
int f[20010][11];

int check_flag(int curr, int next)
{
	if (next == curr - 1 + out && M != 1)
		return 0;
	if (next == curr + 1 + out && M != 1)
		return 1;
	if (next == curr - M + out)
		return 2;
	if (next == curr + M + out)
		return 3;
	if (next == curr - out)
		return 4;
	if (curr == next - 1 + out && M != 1)
		return 5;
	if (curr == next + 1 + out && M != 1)
		return 6;
	if (curr == next - M + out)
		return 7;
	if (curr == next + M + out)
		return 8;
	if (curr == next - out)
		return 9;
	return 10;
}

void no_way(void)
{
	std::cout << "-1\n";
	exit(0);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 0;
	while (i < N)
	{
		std::string str;
		std::cin >> str;
		int j = 0;
		while (j < M)
		{
			arr[i * M + j + 1] = str[j];
			if (str[j] == 'K')
				SRC = i * M + j + 1;
			if (str[j] == 'H')
				SINK = i * M + j + 1;
			j++;
		}
		i++;
	}
	if (N == 1 && M == 1 || SINK == 0 || SRC == 0)
	{
		std::cout << "0\n";
		return 0;
	}
	i = 1;
	while (i <= N * M)
	{
		if (arr[i] != '#')
		{
			if (i % M != 1 && M != 1 && arr[i - 1] != '#')
			{
				if (i == SINK && i - 1 == SRC)
					no_way();
				v[i].push_back(i - 1 + out);
				v[i - 1 + out].push_back(i);
				c[i][0] = INF;
			}
			if (i % M != 0 && arr[i + 1] != '#')
			{
				if (i == SINK && i + 1 == SRC)
					no_way();
				v[i].push_back(i + 1 + out);
				v[i + 1 + out].push_back(i);
				c[i][1] = INF;
			}
			if (i > M && arr[i - M] != '#')
			{
				if (i == SINK && i - M == SRC)
					no_way();
				v[i].push_back(i - M + out);
				v[i - M + out].push_back(i);
				c[i][2] = INF;
			}
			if (i <= (N - 1) * M && arr[i + M] != '#')
			{
				if (i == SINK && i + M == SRC)
					no_way();
				v[i].push_back(i + M + out);
				v[i + M + out].push_back(i);
				c[i][3] = INF;
			}
			v[i + out].push_back(i);
			v[i].push_back(i + out);
			c[i + out][4] = 1;
		}
		i++;
	}
	int cnt = 0;
	while (1)
	{
		int prev[20010];
		std::fill(prev, prev + 20010, -1);
		std::stack < int > q;
		q.push(SRC);
		while (!q.empty())
		{
			int curr = q.top();
			q.pop();
			i = 0;
			int size = v[curr].size();
			while (i < size)
			{
				int next = v[curr][i];
				int next2 = check_flag(curr, next);
				if (prev[next] == -1 && c[curr][next2] > f[curr][next2])
				{
					q.push(next);
					prev[next] = curr;
					if (next == SINK + out)
						break ;
				}
				i++;
			}
		}
		if (prev[SINK + out] == -1)
			break ;
		i = SINK + out;
		int amount = INF;
		while (i != SRC)
		{
			int next = check_flag(prev[i], i);
			amount = MIN(amount, c[prev[i]][next] - f[prev[i]][next]);
			i = prev[i];
		}
		i = SINK + out;
		while (i != SRC)
		{
			int next = check_flag(prev[i], i);
			f[prev[i]][next] += amount;
			next = check_flag(i, prev[i]);
			f[i][next] -= amount;
			i = prev[i];
		}
		cnt++;
	}
	std::cout << cnt << "\n";
}