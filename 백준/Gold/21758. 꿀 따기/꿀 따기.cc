#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> v;
std::vector<int> v2;
std::vector<int> v3;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		std::cin >> num;
		v.push_back(num);
		if (!v2.empty())
			v2.push_back(v2.back() + num);
		else
			v2.push_back(num);
	}
	v3.push_back(v2[N - 1]);
	for (int i = N - 1; i > 0; i--)
		v3.push_back(v3.back() - v[N - 1 - i]);
	int tmp = 0;
	for (int i = N - 2; i >= 1; i--)
	{
		int curr = v2[i - 1] - v[i];
		if (tmp < curr + v2[N - 2])
			tmp = curr + v2[N - 2];
	}
	int max = tmp;
	tmp = 0;
	for (int i = 1; i <= N - 2; i++)
	{
		int curr = v3[i + 1] - v[i];
		if (tmp < curr + v3[1])
			tmp = curr + v3[1];
	}
	max < tmp ? max = tmp : 0;
	for (int i = 1; i < N - 1; i++)
	{
		int curr = v2[i] + v3[i] - v[0] - v[N - 1];
		if (max < curr)
			max = curr;
	}
	std::cout << max << "\n";
}