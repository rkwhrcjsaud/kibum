#include <string>
#include <vector>

using namespace std;

int sol(int n, int left, int right, int cntleft, int cntright)
{
    if (cntleft > cntright)
        return 0;
    if (n == 0)
        return 1;
    int ret = 0;
    if (left)
        ret += sol(n - 1, left - 1, right, cntleft + 1, cntright);
    if (right)
        ret += sol(n - 1, left, right - 1, cntleft, cntright + 1);
    return ret;
}

int solution(int n) {
    int answer = sol(n * 2, n, n, 0, 0);
    return answer;
}