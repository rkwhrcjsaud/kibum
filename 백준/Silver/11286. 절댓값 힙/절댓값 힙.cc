#include <iostream>
#include <vector>

int n;
int v[2000004];
int	size;

typedef long long ll;

void	swap(int a, int b)
{
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

void	insert(int k)
{
	size++;
	v[size] = k;
	int idx = size;
	while (1)
	{
		if (abs(v[idx >> 1]) > abs(v[idx]) && idx >> 1 != 0)
			swap(idx >> 1, idx);
		else if (abs(v[idx >> 1]) == abs(v[idx]) && v[idx >> 1] > v[idx] && idx >> 1 != 0)
			swap(idx >> 1, idx);
		else
			break ;
		idx = idx >> 1;
	}
}

void	pop()
{
	if (size == 0)
	{
		std::cout << "0\n";
		return ;
	}
	std::cout << v[1] << "\n";
	int idx = size;
	swap(idx, 1);
	v[size] = 0;
	size--;
	ll i = 1;
	while (1)
	{
		ll left = i << 1;
		ll right = (i << 1) + 1;
		if (size < left)
			break ;
		else if (size == left)
		{
			if (abs(v[left]) < abs(v[right]))
			{
				swap(left, i);
				i = left;
			}
			else if (abs(v[left]) == abs(v[right]) && v[left] < v[right])
			{
				swap(left, i);
				i = left;
			}
			else
				break ;
		}
		else
		{
			if (abs(v[left]) < abs(v[right]))
			{
				if (abs(v[left]) < abs(v[i]))
				{
					swap(left, i);
					i = left;
				}
				else if (abs(v[left]) == abs(v[i]) && v[left] < v[i])
				{
					swap(left, i);
					i = left;
				}
				else
					break ;
			}
			else if (abs(v[left]) == abs(v[right]))
			{
				if (v[left] <= v[right])
				{
					if (abs(v[left]) < abs(v[i]))
					{
						swap(left, i);
						i = left;
					}
					else if (abs(v[left]) == abs(v[i]) && v[left] < v[i])
					{
						swap(left, i);
						i = left;
					}
					else
						break ;
				}
				else if (v[left] > v[right])
				{
					if (abs(v[right]) < abs(v[i]))
					{
						swap(right, i);
						i = right;
					}
					else if (abs(v[right]) == abs(v[i]) && v[right] < v[i])
					{
						swap(right, i);
						i = right;
					}
					else
						break ;
				}
			}
			else if (abs(v[left]) > abs(v[right]))
			{
				if (abs(v[right]) < abs(v[i]))
				{
					swap(right, i);
					i = right;
				}
				else if (abs(v[right]) == abs(v[i]) && v[right] < v[i])
				{
					swap(right, i);
					i = right;
				}
				else
					break ;
			}
			else
				break ;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 1;
	while (i++ <= n)
	{
		int temp;
		std::cin >> temp;
		if (temp)
			insert(temp);
		else
			pop();
	}
}