#include <iostream>

int arr[3][2];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int i = -1;
	while (++i < 3)
		std::cin >> arr[i][0] >> arr[i][1];
	int temp = ((arr[1][0] - arr[0][0]) * (arr[2][1] - arr[0][1])) - ((arr[2][0] - arr[0][0]) * (arr[1][1] - arr[0][1]));
	std::cout << (temp > 0) - (temp < 0) << "\n";
}
