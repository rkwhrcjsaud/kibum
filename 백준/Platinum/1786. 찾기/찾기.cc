#include <iostream>
#include <cstring>
#include <vector>

std::string T, P;
std::vector <int> v;
int max_k[1000001];
int cnt;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	getline(std::cin, T);
	getline(std::cin, P);
	int i = 1, j = 0;
	int size_T = T.length();
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
	i = 0;
	j = 0;
	while (i < size_T)
	{
		while (T[i] != P[j] && j > 0)
			j = max_k[j - 1];
		if (T[i] == P[j])
		{
			i++;
			j++;
		}
		else
			i++;
		if (j == size_P)
		{
			v.push_back(i - j + 1);
			cnt++;
		}
	}
	std::cout << cnt << "\n";
	i = 0;
	while (i < v.size())
		std::cout << v[i++] << " ";
	std::cout << "\n";
}