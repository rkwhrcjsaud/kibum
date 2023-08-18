#include <iostream>
#include <vector>

int n, max;
int arr[1000002];
std::vector<int> v;

int solve(int left, int right, int k)
{
	if (left > right)
		return left;
	int mid = (left + right) / 2;
	if (v[mid] > k)
		return solve(left, mid - 1, k);
	if (v[mid] < k)
		return solve(mid + 1, right, k);
	return mid;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 1;
	while (i <= n)
		std::cin >> arr[i++];
	v.push_back(arr[1]);
	i = 2;
	while (i <= n)
	{
		if (v.back() < arr[i])
			v.push_back(arr[i]);
		else
		{
			int temp = solve(0, v.size(), arr[i]);
			v[temp] = arr[i];
		}
		i++;
	}
	std::cout << v.size() << "\n";
}