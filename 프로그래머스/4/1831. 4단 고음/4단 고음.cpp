int sol(int n, int needM, int needP, int cntM, int cntP)
{
    if (cntM * 2 > cntP)
        return 0;
    if (n < 3)
        return 0;
    if (n == 3 && needM == 1 && needP == 0)
        return 1;
    int ret = 0;
    if (needP)
        ret += sol(n - 1, needM, needP - 1, cntM, cntP + 1);
    if (needM && n % 3 == 0)
        ret += sol(n / 3, needM - 1, needP, cntM + 1, cntP);
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
    int answer = 0;
    long long tmp = 3;
    int cnt = 0;
    while (tmp < n)
    {
        tmp *= 3;
        cnt++;
    }
    answer = sol(n - 2, cnt, cnt * 2 - 2, 0, 2);
    return answer;
}