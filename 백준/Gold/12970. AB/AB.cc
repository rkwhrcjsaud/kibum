#include <iostream>

int N, K;

int countA(std::string str)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
        if (str[i] == 'A')
            cnt++;
    return cnt;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    if (K > (N / 2) * ((N + 1) / 2))
    {
        std::cout << "-1\n";
        return 0;
    }
    std::string str;
    for (int i = 0; i < N; i++)
        str += "B";
    int cnt = 0;
    while (cnt != K)
    {
        int idx = N - 1;
        cnt -= countA(str);
        str[idx] = 'A';
        while (idx > 0 && str[idx - 1] == 'B' && cnt != K)
        {
            str[idx] = 'B';
            idx--;
            str[idx] = 'A';
            cnt++;
        }
    }
    std::cout << str << '\n';
}