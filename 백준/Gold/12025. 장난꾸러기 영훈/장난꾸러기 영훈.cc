#include <iostream>

std::string S;
long long K;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> S >> K;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '6')
            S[i] = '1';
        if (S[i] == '7')
            S[i] = '2';
    }
    K--;
    for (long long i = S.size() - 1; i >= 0 && K; i--)
    {
        if (S[i] == '1' || S[i] == '6')
        {
            K & 1 ? S[i] = '6' : S[i] = '1';
            K >>= 1;
        }
        if (S[i] == '2' || S[i] == '7')
        {
            K & 1 ? S[i] = '7' : S[i] = '2';
            K >>= 1;
        }
    }
    if (K)
        std::cout << "-1\n";
    else
        std::cout << S << '\n';
}