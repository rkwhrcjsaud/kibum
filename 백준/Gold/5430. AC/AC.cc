#include <iostream>
#include <deque>

int T;

class AC
{
	public :
		std::deque <int> dq;
		bool order;
		AC():order(0){};
		~AC(){};
		void command_R()
		{
			order = !order;
		}
		int command_D()
		{
			if (dq.empty())
			{
				std::cout << "error\n";
				return 1;
			}
			if (order)
				dq.pop_back();
			else
				dq.pop_front();
			return 0;
		}
		void	print_dq()
		{
			std::cout << "[";
			while (!dq.empty())
			{
				if (order)
				{
					std::cout << dq.back();
					dq.pop_back();
				}
				else
				{
					std::cout << dq.front();
					dq.pop_front();
				}
				if (!dq.empty())
					std::cout << ",";
			}
			std::cout << "]\n";
		}
		void	in_dq( int num )
		{
			dq.push_back(num);
		}
};

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		std::string str;
		std::cin >> str;
		int len = str.length();
		int n;
		std::cin >> n;
		int i = 1;
		AC ans;
		std::string arr;
		std::cin >> arr;
		int len2 = arr.length();
		while (i < len2 - 1)
		{
			int num = 0;
			while (arr[i] >= '0' && arr[i] <= '9')
			{
				num *= 10;
				num += arr[i] - '0';
				i++;
			}
			ans.in_dq(num);
			i++;
		}
		i = 0;
		while (i < len)
		{
			if (str[i] == 'R')
				ans.command_R();
			else
			{
				if (ans.command_D())
					break ;
			}
			i++;
			if (i == len)
				ans.print_dq();
		}
	}
}