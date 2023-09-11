#include <iostream>

int N;
std::pair <char, char> arr[27];

void	preorder(char a)
{
	if (a != '.')
	{
		std::cout << a;
		preorder(arr[a - 'A'].first);
		preorder(arr[a - 'A'].second);
	}
}

void	inorder(char a)
{
	if (a != '.')
	{
		inorder(arr[a - 'A'].first);
		std::cout << a;
		inorder(arr[a - 'A'].second);
	}
}

void	postorder(char a)
{
	if (a != '.')
	{
		postorder(arr[a - 'A'].first);
		postorder(arr[a - 'A'].second);
		std::cout << a;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
	{
		char a, b, c;
		std::cin >> a >> b >> c;
		arr[a - 'A'].first = b;
		arr[a - 'A'].second = c;
		i++;
	}
	preorder('A');
	std::cout << "\n";
	inorder('A');
	std::cout << "\n";
	postorder('A');
	std::cout << "\n";
}