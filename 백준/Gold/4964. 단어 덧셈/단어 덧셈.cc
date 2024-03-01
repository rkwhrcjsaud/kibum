#include <iostream>
#include <vector>

int cnt;
std::vector<std::string> equation;
std::vector<char> character;

void solution(int charToNum[], char numToChar[], int depth)
{
	if (depth == (int)character.size())
	{
		int num = 0;
		for (std::vector<std::string>::iterator it = equation.begin(); it != equation.end(); it++)
		{
			int tmp = 0;
			if (charToNum[(*it)[0] - 'A'] == 0 && it->size() > 1)
				return ;
			for (std::string::iterator it2 = it->begin(); it2 != it->end(); it2++)
			{
				tmp *= 10;
				tmp += charToNum[*it2 - 'A'];
			}
			if (*it == equation.back())
				num -= tmp;
			else
				num += tmp;
		}
		if (num == 0)
			cnt++;
		return ;
	}
	for (int i = 0; i < 10; i++)
	{
		if (!numToChar[i])
		{
			numToChar[i] = character[depth];
			charToNum[character[depth] - 'A'] = i;
			solution(charToNum, numToChar, depth + 1);
			numToChar[i] = 0;
			charToNum[character[depth] - 'A'] = 0;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	while (1)
	{
		std::cin >> N;
		if (N == 0)
			break ;
		bool visited[27] = {false, };
		char numToChar[11] = {0, };
		int charToNum[27] = {0, };
		cnt = 0;
		equation.clear();
		character.clear();
		for (int i = 0; i < N; i++)
		{
			std::string tmp;
			std::cin >> tmp;
			equation.push_back(tmp);
			for (std::string::iterator it = tmp.begin(); it != tmp.end(); it++)
			{
				if (!visited[*it - 'A'])
				{
					visited[*it - 'A'] = true;
					character.push_back(*it);
				}
			}
		}
		solution(charToNum, numToChar, 0);
		std::cout << cnt << '\n';
	}
}
