#include <iostream>

int N;
std::string	num[16];
long long dp[(1 << 15) + 1][100];
int memory[51];
int memory_str[16];
int	K;

int	calc_mod(std::string str)
{
	int i = 0;
	int len = str.length();
	int mod = 0;
	while (i < len)
	{
		mod *= 10;
		mod += str[i] - '0';
		mod %= K;
		i++;
	}
	return (mod);
}

long long GCD(long long head, long long body)
{
	while (head != 0)
	{
		long long temp = body % head;
		body = head;
		head = temp;
	}
	return (body);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
		std::cin >> num[i++];
	std::cin >> K;
	i = 0;
	while (i < N)
	{
		memory_str[i] = calc_mod(num[i]);
		i++;
	}
	memory[0] = 1 % K;
	dp[0][0] = 1;
	i = 1;
	while (i < 51)
	{
		memory[i] = (memory[i - 1] * 10) % K;
		i++;
	}
	int bit = 0;
	while (bit < (1 << N))
	{
		i = 0;
		while (i < N)
		{
			if ((bit & (1 << i)) == 0)
			{
				int j = 0;
				while (j < K)
				{
					dp[bit | (1 << i)][(((j * memory[num[i].length()]) % K) + memory_str[i]) % K] += dp[bit][j];
					j++;
				}
			}
			i++;
		}
		bit++;
	}
	long long head = dp[(1 << N) - 1][0];
	long long body = head;
	i = 1;
	while (i < K)
		body += dp[(1 << N) - 1][i++];
	long long gcd = GCD(head, body);
	head /= gcd;
	body /= gcd;
	std::cout << head << "/" << body << "\n";
}
