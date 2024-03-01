#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int N;
std::vector<int> v;
int arr[26];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < (int)str.length(); j++)
			arr[str[j] - 'A'] += (int)pow(10, (int)str.length() - j - 1);
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i])
			v.push_back(arr[i]);
	}
	std::sort(v.begin(), v.end(), std::greater<int>());
	int ans = 0;
	for (int i = 0, j = 9; i < (int)v.size(); i++, j--)
		ans += v[i] * j;
	std::cout << ans << '\n';
}
