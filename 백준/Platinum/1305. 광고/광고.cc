#include <iostream>
#include <cstring>

std::string P;
int len;
int max_k[1000001];
int cnt;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> len;
	std::cin.ignore();
	getline(std::cin, P);
	int i = 1, j = 0;
	int size_P = P.length();
	while (i < size_P)
	{
		while (P[i] != P[j] && j > 0)
			j = max_k[j - 1];
		if (P[i] == P[j])
		{
			max_k[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			max_k[i] = 0;
			i++;
		}
	}
	std::cout << len - max_k[size_P - 1] << "\n";
}