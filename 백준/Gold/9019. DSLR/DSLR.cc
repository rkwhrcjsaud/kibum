#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

int T;
int	visited[10002][5];

int	calc_L(int num)
{
	int a = num / 1000;
	num %= 1000;
	int b = num / 100;
	num %= 100;
	int c = num / 10;
	num %= 10;
	int d = num;
	num = (((b * 10 + c) * 10) + d) * 10 + a;
	return num;
}

int	calc_R(int num)
{
	int a = num / 1000;
	num %= 1000;
	int b = num / 100;
	num %= 100;
	int c = num / 10;
	num %= 10;
	int d = num;
	num = (((d * 10 + a) * 10) + b) * 10 + c;
	return num;
}

void	bfs(int s, int e)
{
	std::queue < int > q;
	visited[s][0] = true;
	visited[s][1] = 10000;
	visited[s][2] = 10000;
	visited[s][3] = 10000;
	visited[s][4] = 10000;
	q.push(s);
	while (!q.empty())
	{
		int cur = q.front();
		int cur_2 = cur * 2;
		int cur_minus = cur - 1;
		if (cur_2 >= 10000)
			cur_2 %= 10000;
		if (cur_minus == -1)
			cur_minus = 9999;
		q.pop();
		if (cur == e)
			return ;
		if (visited[cur_2][0] == -1)
		{
			visited[cur_2][1] = cur;
			visited[cur_2][0] = 1;
			q.push(cur_2);
		}
		if (visited[cur_minus][0] == -1)
		{
			visited[cur_minus][0] = 1;
			visited[cur_minus][2] = cur;
			q.push(cur_minus);
		}
		if (visited[calc_L(cur)][0] == -1)
		{
			visited[calc_L(cur)][0] = 1;
			visited[calc_L(cur)][3] = cur;
			q.push(calc_L(cur));
		}
		if (visited[calc_R(cur)][0] == -1)
		{
			visited[calc_R(cur)][0] = 1;
			visited[calc_R(cur)][4] = cur;
			q.push(calc_R(cur));
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		int s, e;
		std::cin >> s >> e;
		std::memset(visited, -1, sizeof(visited));
		bfs(s, e);
		std::stack < char > st;
		while (visited[e][1] != 10000 && visited[e][2] != 10000 && visited[e][3] != 10000 && visited[e][4] != 10000)
		{
			if (visited[e][1] != -1)
			{
				st.push('D');
				e = visited[e][1];
			}
			else if (visited[e][2] != -1)
			{
				st.push('S');
				e = visited[e][2];
			}
			else if (visited[e][3] != -1)
			{
				st.push('L');
				e = visited[e][3];
			}
			else if (visited[e][4] != -1)
			{
				st.push('R');
				e = visited[e][4];
			}
		}
		while (!st.empty())
		{
			std::cout << st.top();
			st.pop();
		}
		std::cout << "\n";
	}
}