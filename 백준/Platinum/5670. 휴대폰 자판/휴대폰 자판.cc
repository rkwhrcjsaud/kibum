#include <iostream>
#include <vector>
#include <map>

int cnt;

struct Trie
{
	std::map <char, Trie*>	m;
	int						num;

	void	insert(std::string str, int idx)
	{
		if (str.size() == idx)
			return ;
		if (m.find(str[idx]) == m.end())
		{
			Trie* trie = new Trie;
			trie->num = 1;
			trie->insert(str, idx + 1);
			m.insert(std::make_pair(str[idx], trie));
		}
		else
		{
			m[str[idx]]->num++;
			m[str[idx]]->insert(str, idx + 1);
		}
	}
};

void	dfs(Trie a)
{
	std::map <char, Trie*>::iterator iter = a.m.begin();
	while (iter != a.m.end())
	{
		if (a.num != iter->second->num)
			cnt+= iter->second->num;
		if (iter->second)
			dfs(*iter->second);
		iter++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	while (1)
	{
		int N;
		cnt = 0;
		std::cin >> N;
		if (std::cin.eof())
			break ;
		Trie trie;
		trie.num = N;
		int i = 0;
		while (i < N)
		{
			std::string str;
			std::cin >> str;
			trie.insert(str, 0);
			i++;
		}
		char b = 'a';
		while (b <= 'z')
		{
			if (trie.m.find(b) != trie.m.end())
			{
				cnt += trie.m.find(b)->second->num;
				dfs(*trie.m.find(b)->second);
			}
			b++;
		}
		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout << (double)cnt / N << "\n";
	}
}