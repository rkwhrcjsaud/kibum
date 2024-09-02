#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int N;

bool sol(int mid, vector<int> &cores)
{
    int tmp = 0;
    for (int i = 0; i < cores.size(); i++)
    {
        tmp += mid / cores[i] + 1;
        if (tmp >= N)
            return false;
    }
    return true;
}

int solution(int n, vector<int> cores) {
    N = n;
    int answer = 0;
    if (n <= cores.size())
        return n;
    int s = 0, e = 5e8;
    int t = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (sol(mid, cores))
        {
            s = mid + 1;
            t = max(t, mid);
        }
        else
            e = mid - 1;
    }
    int tmp = 0;
    for (int i = 0; i < cores.size(); i++)
        tmp += t / cores[i] + 1;
    t++;
    for (int i = 0; i < cores.size(); i++)
    {
        if (t % cores[i])
            continue ;
        tmp++;
        if (tmp == n)
        {
            answer = i + 1;
            break ;
        }
    }
    return answer;
}