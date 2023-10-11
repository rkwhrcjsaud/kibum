#include <iostream>

#define MIN(a, b) (a < b ? a : b)
int N;
std::string s1;
std::string s2;
int arr[10001];
int dest[10001];
int dp[10001][11];
int child[10001][11];

int d(int idx, int turn)
{
	if (dp[idx][turn])
		return dp[idx][turn];
	if (idx == N)
		return 0;
	int left = (dest[idx] - arr[idx] - turn + 20) % 10;
	int right = (10 - left) % 10;
	int child1 = d(idx + 1, (turn + left) % 10) + left;
	int child2 = d(idx + 1, turn) + right;
	if (child1 < child2)
		child[idx][turn] = left;
	else
		child[idx][turn] = -right;
	return dp[idx][turn] = MIN(child1, child2);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	std::cin >> s1 >> s2;
	int i = 0;
	while (i < N)
	{
		arr[i] = s1[i] - '0';
		dest[i] = s2[i] - '0';
		i++;
	}
	std::cout << d(0, 0) << "\n";
	i = 0;
	int parent_turn = 0;
	while (i < N)
	{
		int child_turn = child[i][parent_turn];
		std::cout << i + 1 << " " << child_turn << "\n";
		if (child_turn > 0)
		{
			parent_turn += child_turn;
			parent_turn %= 10;
		}
		i++;
	}
}
