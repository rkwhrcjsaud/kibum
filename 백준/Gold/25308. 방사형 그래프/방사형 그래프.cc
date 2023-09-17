#include <iostream>
#include <vector>

double arr[10];
bool visited[10];

bool check(double next, double curr, double prev)
{
	return (prev * next <= (prev + next) * curr * 0.7071);
}

int	dfs(int next, int curr, int prev, int depth)
{
	int cnt = 0;
	if (next == curr || curr == prev || next == prev)
		return (0);
	if (depth == 5)
	{
		if (check(arr[8], arr[next], arr[curr]))
			cnt += dfs(8, next, curr, depth + 1);
		return cnt;
	}
	if (depth == 6)
		return (check(arr[9], arr[next], arr[curr]));
	int i = 0;
	while (i < 8)
	{
		if (visited[i] == false && check(arr[i], arr[next], arr[curr]))
		{
			visited[i] = true;
			cnt += dfs(i, next, curr, depth + 1);
			visited[i] = false;
		}
		i++;
	}
	return (cnt);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int i = 0;
	while (i < 8)
		std::cin >> arr[i++];
	i = 1;
	int cnt = 0;
	visited[0] = true;
	arr[9] = arr[0];
	while (i < 8)
	{
		int j = 1;
		arr[8] = arr[i];
		while (j < 8)
		{
			visited[i] = true;
			visited[j] = true;
			if (check(arr[j], arr[0], arr[i]))
				cnt += dfs(j, 0, i, 0);
			visited[i] = false;
			visited[j] = false;
			j++;
		}
		i++;
	}
	std::cout << cnt * 8 << "\n";
}