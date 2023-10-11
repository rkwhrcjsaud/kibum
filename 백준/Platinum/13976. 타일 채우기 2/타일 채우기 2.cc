#include <iostream>

#define DIV 1000000007
typedef long long ll;
ll N;
ll arr[3][3];
ll ans[3][3];
ll temp[3][3];
bool	arr_p[10000];

void	arrPowerOrigin()
{
	int i = 1;
	while (i <= 2)
	{
		int j = 1;
		while (j <= 2)
		{
			ll t = 0;
			int k = 1;
			while (k <= 2)
			{
				t += ((temp[i][k] % DIV) * (arr[k][j] % DIV)) % DIV;
				k++;
			}
			ans[i][j] = t;
			j++;
		}
		i++;
	}
}

void	arrPower()
{
	int i = 1;
	while (i <= 2)
	{
		int j = 1;
		while (j <= 2)
		{
			ll t = 0;
			int k = 1;
			while (k <= 2)
			{
				t += ((temp[i][k] % DIV) * (temp[k][j] % DIV)) % DIV;
				k++;
			}
			ans[i][j] = t;
			j++;
		}
		i++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	if (N % 2 == 1)
	{
		std::cout << "0\n";
		return 0;
	}
	if (N == 2)
	{
		std::cout << "3\n";
		return 0;
	}
	arr[1][1] = ans[1][1] = 4;
	arr[1][2] = ans[1][2] = -1;
	arr[2][1] = ans[2][1] = 1;
	arr[2][2] = ans[2][2] = 0;
	ll B = (N / 2) - 1;
	int i = 1;
	while (B > 1)
	{
		if (B % 2 == 1)
			arr_p[i] = true;
		i++;
		B /= 2;
	}
	while (--i > 0)
	{
		temp[1][1] = ans[1][1];
		temp[1][2] = ans[1][2];
		temp[2][1] = ans[2][1];
		temp[2][2] = ans[2][2];
		arrPower();
		if (arr_p[i])
		{
			temp[1][1] = ans[1][1];
			temp[1][2] = ans[1][2];
			temp[2][1] = ans[2][1];
			temp[2][2] = ans[2][2];
			arrPowerOrigin();
		}
	}
	ll ans_l = ((ans[1][1] % DIV) * 3 + ans[1][2]) % DIV;
	if (ans_l < 0)
		ans_l += DIV;
	std::cout << ans_l << "\n";
}
