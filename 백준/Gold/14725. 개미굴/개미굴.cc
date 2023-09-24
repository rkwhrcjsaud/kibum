#include <iostream>
#include <vector>
#include <map>

struct Trie
{
	std::map <std::string, Trie*> map;

	void	insert(std::vector<std::string> &v, int idx)
	{
		if (idx == v.size())
			return ;
		if (map.find(v[idx]) == map.end())
		{
			Trie* trie = new Trie;
			map.insert(std::make_pair(v[idx], trie));
		}
		map[v[idx]]->insert(v, idx + 1);
	}
};

int 	N;
Trie	t;

void	dfs(Trie a, int depth)
{
	std::map <std::string, Trie*>::iterator iter = a.map.begin();
	while (iter != a.map.end())
	{
		int n = depth;
		while (n--)
			std::cout << "--";
		std::cout << iter->first << "\n";
		if (iter->second)
			dfs(*iter->second, depth + 1);
		iter++;
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
		int n;
		std::cin >> n;
		std::vector <std::string> v(n);
		int j = 0;
		while (j < n)
			std::cin >> v[j++];
		t.insert(v, 0);
		i++;
	}
	dfs(t, 0);
}