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
vector<int> cards;
int arr[1000001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	cin >> N;
	cards.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> cards[i];
		for (int j = 1; j * j <= cards[i]; j++)
		{
			if (cards[i] % j == 0)
			{
				arr[j]++;
				if (j != cards[i] / j)
					arr[cards[i] / j]++;
			}
		}
		for (int j = cards[i]; j <= 1000000; j += cards[i])
			arr[j]--;
	}
	for (int i = 0; i < N; i++)
		cout << arr[cards[i]] << ' ';
	cout << '\n';
}