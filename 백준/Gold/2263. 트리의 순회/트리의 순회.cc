#include <iostream>

int N;
int idx[100002];
int in[100002];
int post[100002];

void	rec(int si, int ei, int sp, int ep)
{
	if (si > ei || sp > ep)
		return ;
	int root = idx[post[ep]];
	std::cout << in[root] << " ";
	rec(si, root - 1, sp, sp + root - si - 1);
	rec(root + 1, ei, sp + root - si, ep - 1);
}

int main(void)
{
	std::cin >> N;
	int i = 1;
	while (i <= N)
	{
		std::cin >> in[i];
		idx[in[i]] = i;
		i++;
	}
	i = 1;
	while (i <= N)
		std::cin >> post[i++];
	rec(1, N, 1, N);
	std::cout << "\n";
}