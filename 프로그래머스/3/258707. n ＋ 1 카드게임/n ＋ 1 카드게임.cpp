#include <string>
#include <vector>

using namespace std;
int n;
int arr[1010] = {0, };
// 6 <= n < 1000, n은 6의 배수
// 1 <= cards[i] <= n, 중복 없음(1, 2, 3 ..., n)

int sol(int idx, int coin, vector<int> &cards, int pass)
{
    if (idx == n)
        return 1;
    int a = cards[idx];
    int b = cards[idx + 1];
    
    if (arr[n + 1 - a] == 1 && coin > 0)
    {
        pass++;
        coin--;
    }
    else
        arr[a] = 2;
    if (arr[n + 1 - b] == 1 && coin > 0)
    {
        pass++;
        coin--;
    }
    else
        arr[b] = 2;
    if (pass == 0 && coin > 1)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            if (arr[i] == 2 && arr[n + 1 - i] == 2)
            {
                arr[i] = 0;
                arr[n + 1 - i] = 0;
                pass++;
                coin -= 2;
                break ;
            }
        }
    }
    if (pass == 0)
        return 1;
    return (1 + sol(idx + 2, coin, cards, pass - 1));
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    n = cards.size();
    int pass = 0;
    for (int i = 0; i < n / 3; ++i)
    {
        arr[cards[i]]++;
        if (arr[n + 1 - cards[i]])
            pass++;
    }
    answer = sol(n / 3, coin, cards, pass);
    return answer;
}