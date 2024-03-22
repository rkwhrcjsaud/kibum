#include <iostream>
#include <vector>

int N, cnt;
std::vector<int> word;

void solved(int idx, int mask)
{
    if (idx == N)
    {
        if (mask == (1 << 26) - 1)
            cnt++;
        return ;
    }
    solved(idx + 1, mask | word[idx]);
    solved(idx + 1, mask);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        int bit = 0;
        for (int j = 0; j < (int)str.length(); j++)
            bit |= (1 << (str[j] - 'a'));
        word.push_back(bit);
    }
    solved(0, 0);
    std::cout << cnt << '\n';
}
