#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int N;
typedef long long ll;

ll check[10];

void solve(int a, int b, int digit)
{
	while (a % 10 && a <= b)
	{
		for (int i = a; i; i /= 10)
			check[i % 10] += digit;
		a++;
	}
	if (a > b)
		return;
	while (b % 10 != 9 && a <= b)
	{
		for (int i = b; i; i /= 10)
			check[i % 10] += digit;
		b--;
	}
	ll cnt = (b / 10 - a / 10 + 1);
	for (int i = 0; i < 10; i++)
		check[i] += cnt * digit;
	solve(a / 10, b / 10, digit * 10);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	cin >> N;
	solve(1, N, 1);
	for (int i = 0; i < 10; i++)
		cout << check[i] << ' ';
	cout << '\n';
}