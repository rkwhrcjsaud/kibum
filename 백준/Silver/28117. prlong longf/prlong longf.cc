#include <iostream>

int N, cnt;
std::string str;
int	fibo[22];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> str;
	int i = 2;
	fibo[0] = 1;
	fibo[1] = 2;
	while (i < 22)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		i++; 
	}
	i = 0;
	cnt = 1;
	while (i < N)
	{
		if (str.substr(i, 8) == "longlong")
		{
			int temp = 0;
			while (str.substr(i, 8) == "longlong")
			{
				temp++;
				i += 4;
			}
			cnt *= fibo[temp];
		}
		i++;
	}
	std::cout << cnt << "\n";
}