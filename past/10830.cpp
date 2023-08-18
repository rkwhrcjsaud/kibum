#include <iostream>
#define DIV 1000

typedef	unsigned long long int ull;
ull N, B;
int arr[7][7];
int	temp[7][7];
int ans[7][7];
int	arr_p[33];

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
	std::cin >> N >> B;
	int i = 1;
	while (i <= N)
	{
		int j = 1;
		while (j <= N)
		{
			std::cin >> arr[i][j];
			ans[i][j] = arr[i][j];
			j++;
		}
		i++;
	}
	i = 1;
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
	i = 1;
	while (i <= N)
	{
		int j = 1;
		while (j <= N)
			std::cout << ans[i][j++] % DIV << " ";
		std::cout << "\n";
		i++;
	}
}
