#include <iostream>

int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    std::string A, B;
    std::cin >> A >> B;
    int ans = -1;
    int cnt = 0;
    std::string copyA = A;
    for (int i = 0; i < N - 1; i++)
    {
        if (copyA[i] != B[i])
        {
            cnt++;
            copyA[i] = copyA[i] == '0' ? '1' : '0';
            copyA[i + 1] = copyA[i + 1] == '0' ? '1' : '0';
            if (i < N - 2)
                copyA[i + 2] = copyA[i + 2] == '0' ? '1' : '0';
        }
    }
    if (copyA == B)
        ans = cnt;
    copyA = A;
    cnt = 1;
    copyA[0] = copyA[0] == '0' ? '1' : '0';
    copyA[1] = copyA[1] == '0' ? '1' : '0';
    for (int i = 0; i < N - 1; i++)
    {
        if (copyA[i] != B[i])
        {
            cnt++;
            copyA[i] = copyA[i] == '0' ? '1' : '0';
            copyA[i + 1] = copyA[i + 1] == '0' ? '1' : '0';
            if (i < N - 2)
                copyA[i + 2] = copyA[i + 2] == '0' ? '1' : '0';
        }
    }
    if (copyA == B)
        ans = ans == -1 ? cnt : std::min(ans, cnt);
    std::cout << ans << '\n';
}
