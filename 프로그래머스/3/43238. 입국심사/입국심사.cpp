#include <string>
#include <vector>

using namespace std;
typedef long long ll;

bool check(int n, ll mid, vector<int> &times)
{
    ll cnt = 0;
    for (int i = 0; i < times.size(); i++)
    {
        cnt += mid / times[i];
        if (cnt >= n)
            return true;
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 1e18;
    ll l = 0, r = 1e18;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(n, mid, times))
        {
            answer = min(mid, answer);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return answer;
}