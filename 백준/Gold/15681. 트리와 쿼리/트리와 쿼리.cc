#include <iostream>
#include <vector>

int N, R, Q;
int	subsize[100002];
std::vector <int> v[100002];

void	makeTree(int currentNode, int parentNode)
{
	int i = 0;
	int cnt = 0;
	int size = v[currentNode].size();
	subsize[currentNode] = 1;
	while (i < size)
	{
		if (v[currentNode][i] != parentNode)
		{
			makeTree(v[currentNode][i], currentNode);
			subsize[currentNode] += subsize[v[currentNode][i]];
		}
		i++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> R >> Q;
	int i = 1;
	while (i < N)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		i++;
	}
	makeTree(R, -1);
	i = 1;
	while (i <= Q)
	{
		int U;
		std::cin >> U;
		std::cout << subsize[U] << "\n";
		i++;
	}
}
