#include <iostream>

int AN, AM, BN, BM;
int arrA[102][102];
int arrB[102][102];

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> AN >> AM;
	int i = 1;
	while (i <= AN)
	{
		int j = 1;
		while (j <= AM)
			std::cin >> arrA[i][j++];
		i++;
	}
	i = 1;
	std::cin >> BN >> BM;
	while (i <= BN)
	{
		int j = 1;
		while (j <= BM)
			std::cin >> arrB[i][j++];
		i++;
	}
	i = 1;
	while (i <= AN)
	{
		int j = 1;
		while (j <= BM)
		{
			int temp = 0;
			int k = 1;
			while (k <= AM)
			{
				temp += arrA[i][k] * arrB[k][j];
				k++;
			}
			std::cout << temp << " ";
			j++;
		}
		std::cout << "\n";
		i++;
	}
}
