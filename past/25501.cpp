#include <iostream>

int recursion(const std::string& s, int l, int r, int *d){
	(*d)++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, d);
}

int isPalindrome(const std::string& s){
	int d = 0;
	int r = recursion(s, 0, s.size() - 1, &d);
    return r + (d << 1);
}

int	main(void)
{
	int n;
	std::cin >> n;
	while (n--)
	{
		std::string str;
		std::cin >> str;
		int a = isPalindrome(str);
		std::cout << (a & 1) << " " << (a >> 1) << std::endl;
	}
}