#include <iostream>
#include <algorithm>
#include <vector>

int N;
bool	prime[2001];
int		arr[51];
std::vector <int> A;
std::vector <int> B;
std::vector <int> v[51];
std::vector <int> ans;
bool	visited[51];
int		pos[51];

void	calc_prime(void)
{
	std::fill(prime, prime + 2001, true);
	int i = 1;
	while (++i < 2001)
	{
		if (prime[i] == false)
			continue ;
		int j = 2 * i;
		while (j < 2001)
		{
			prime[j] = false;
			j += i;
		}
	}
}

bool dfs(int node)
{
	int i = 0;
	int size = v[node].size();
	while (i < size)
	{
		if (!visited[v[node][i]])
		{
			visited[v[node][i]] = true;
			if (pos[v[node][i]] == -1 || dfs(pos[v[node][i]]))
			{
				pos[v[node][i]] = node;
				return true;
			}
		}
		i++;
	}
	return false;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
		std::cin >> arr[i++];
	i = 0;
	while (i < N)
	{
		if (arr[i] % 2 == arr[0] % 2)
			A.push_back(i);
		else
			B.push_back(i);
		i++;
	}
	int A_size = A.size();
	int B_size = B.size();
	if (A_size != B_size)
	{
		std::cout << "-1\n";
		return 0;
	}
	calc_prime();
	i = 0;
	while (i < A_size)
	{
		int j = 0;
		while (j < B_size)
		{
			if (prime[arr[A[i]] + arr[B[j]]])
				v[A[i]].push_back(B[j]);
			j++;
		}
		i++;
	}
	i = 0;
	int size = v[A[0]].size();
	while (i < size)
	{
		std::fill(pos, pos + 51, -1);
		int cnt = 1;
		int j = 1;
		while (j < N)
		{
			std::fill(visited, visited + 51, 0);
			visited[0] = true;
			visited[v[A[0]][i]] = true;
			if (dfs(j))
				cnt++;
			j++;
		}
		if (cnt == N / 2)
			ans.push_back(arr[v[A[0]][i]]);
		i++;
	}
	std::sort(ans.begin(), ans.end());
	i = 0;
	size = ans.size();
	if (size == 0)
		std::cout << "-1\n";
	else
	{
		while (i < size)
			std::cout << ans[i++] << " ";
		std::cout << "\n";
	}
}