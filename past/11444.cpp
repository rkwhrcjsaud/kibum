#include <iostream>
#include <cmath>

#include <iostream>
#define DIV 1000000007
#define N 2

typedef	unsigned long long int ull;
ull B;
ull arr[3][3];
ull	temp[3][3];
ull ans[3][3];
bool	arr_p[65];

void	arrPowerOrigin()
{
	int i = 1;
	while (i <= N)
	{
		int j = 1;
		while (j <= N)
		{
			int t = 0;
			int k = 1;
			while (k <= N)
			{
				t += temp[i][k] % DIV * arr[k][j] % DIV;
				k++;
			}
			ans[i][j] = t % DIV;
			j++;
		}
		i++;
	}
}

void	arrPower()
{
	int i = 1;
	while (i <= N)
	{
		int j = 1;
		while (j <= N)
		{
			int t = 0;
			int k = 1;
			while (k <= N)
			{
				t += temp[i][k] % DIV * temp[k][j] % DIV;
				k++;
			}
			ans[i][j] = t % DIV;
			j++;
		}
		i++;
	}
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> B;
	if (B == 0)
	{
		std::cout << "0\n";
		return (0);
	}
	int i = 1;
	arr[1][1] = 1;
	arr[1][2] = 1;
	arr[2][1] = 1;
	arr[2][2] = 0;
	ans[1][1] = 1;
	ans[1][2] = 1;
	ans[2][1] = 1;
	ans[2][2] = 0;
	while (B != 1)
	{
		if (B % 2 == 1)
			arr_p[i] = 1;
		i++;
		B /= 2;
	}
	while (--i > 0)
	{
		int j = 1;
		while (j <= N)
		{
			int k = 1;
			while (k <= N)
			{
				temp[j][k] = ans[j][k];
				k++;
			}
			j++;
		}
		arrPower();
		if (arr_p[i] == 1)
		{
			int j = 1;
			while (j <= N)
			{
				int k = 1;
				while (k <= N)
				{
					temp[j][k] = ans[j][k];
					k++;
				}
				j++;
			}
			arrPowerOrigin();
		}
	}
	std::cout << ans[1][2] % DIV << "\n";
}
