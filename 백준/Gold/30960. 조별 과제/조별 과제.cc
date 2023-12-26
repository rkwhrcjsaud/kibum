#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> v;
std::vector<long long int> v2; // v2는 v의 앞에서 부터 두 원소의 차이의 누적합을 저장한다.
std::vector<long long int> v3; // v3는 v의 뒤에서 부터 두 원소의 차이의 누적합을 저장한다.
std::vector<long long int> v4; // v4는 v에서 n, n + 1, n + 2 (n >= 0 && n + 2 < N)의 원소의 v[n + 2] - v[n]의 값을 저장한다.

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N; // N은 무조건 홀수 3 < N < 500000
	for (int i = 1; i <= N; i++)
	{
		int num; // 1 <= num <= 1000000000
		std::cin >> num;
		v.push_back(num);
	}
	std::sort(v.begin(), v.end());
	std::vector<int>::iterator iter = v.begin();
	while (iter != v.end() - 1)
	{
		if (v2.empty())
		{
			v2.push_back(0);
			v2.push_back(*(iter + 1) - *iter);
		}
		else
			v2.push_back(static_cast<long long int>(*(iter + 1)) - *iter + v2.back());
		iter++;
		iter++;
	}
	iter = v.end() - 1;
	while (iter != v.begin())
	{
		if (v3.empty())
		{
			v3.push_back(0);
			v3.push_back(*iter - *(iter - 1));
		}
		else
			v3.push_back(static_cast<long long int>(*iter) - *(iter - 1) + v3.back());
		iter--;
		iter--;
	}
	for (int i = 0; i < N - 2; i++)
		v4.push_back(static_cast<long long int>(v[i + 2]) - v[i]);
	// 그리디 알고리즘을 이용해 N이 홀수인 것을 활용하여 v의 원소들을 하나의 3개 묶음과 나머지의 2개 묶음으로 나누고, 모든 묶음의 차이의 합 중 최소값을 구한다.
	long long int min = 1000000000000000000;
	for(int i = 0; i < N - 2; i += 2)
		min = std::min(min, v2[i / 2] + v3[(N - i - 3) / 2] + v4[i]);
	std::cout << min << "\n";
}