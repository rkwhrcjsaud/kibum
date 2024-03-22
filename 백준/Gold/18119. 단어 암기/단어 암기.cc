#include <iostream>
#include <vector>

int N, M;
int mask;
std::vector<int> word;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        int bit = 0;
        for (int j = 0; j < (int)str.length(); j++)
            bit |= (1 << (str[j] - 'a'));
        word.push_back(bit);
        mask |= bit;
    }
    for (int i = 0; i < M; i++)
    {
        int tmp;
        char c;
        std::cin >> tmp >> c;
        int cnt = 0;
        mask ^= (1 << (c - 'a'));
        for (int j = 0; j < N; j++)
            if ((word[j] & mask) == word[j])
                cnt++;
        std::cout << cnt << '\n';
    }
}
