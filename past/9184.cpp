#include <iostream>

int	mem[21][21][21];
int ans;

int	dp(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return (1);
	else if (a > 20 || b > 20 || c > 20)
		return (dp(20, 20, 20));
	else if (mem[a][b][c])
		return (mem[a][b][c]);
	else if (a < b && b < c)
	{
		mem[a][b][c] = dp(a, b, c - 1) + dp(a, b - 1, c - 1) - dp(a, b - 1, c);
		return (mem[a][b][c]);
	}
	mem[a][b][c] = dp(a - 1, b, c) + dp(a - 1, b - 1, c) + dp(a - 1, b, c - 1) - dp(a - 1, b - 1, c - 1);
	return (mem[a][b][c]);
}

int main(void)
{
	while (1)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break ;
		ans = dp(a, b, c);
		std::cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << "\n";
	}
}