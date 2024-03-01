#include <iostream>
#include <algorithm>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string S, T;
	std::cin >> S >> T;
	while (S.size() < T.size())
	{
		if (T[T.size() - 1] == 'A')
			T.pop_back();
		else
		{
			T.pop_back();
			std::reverse(T.begin(), T.end());
		}
	}
	std::cout << (S == T ? 1 : 0) << '\n';
}
