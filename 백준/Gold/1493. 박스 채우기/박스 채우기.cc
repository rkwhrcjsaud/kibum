#include <iostream>

int L, W, H, N;
int arr[21];
int cnt;

void solution(int sl, int sw, int sh, int el, int ew, int eh, int max)
{
    if (sl == el || sw == ew || sh == eh)
        return ;
    bool flag = false;
    int next = max;
    for (int i = max; i >= 0; i--)
    {
        if (el - sl >= (1 << i)
            && ew - sw >= (1 << i)
            && eh - sh >= (1 << i)
            && arr[i] > 0)
        {
            flag = true;
            arr[i]--;
            cnt++;
            next = i;
            break ;
        }
    }
    if (!flag)
    {
        std::cout << -1 << '\n';
        exit(0);
    }
    int midL = sl + (1 << next);
    int midW = sw + (1 << next);
    int midH = sh + (1 << next);
    solution(midL, sw, sh, el, midW, midH, next);
    solution(sl, midW, sh, midL, ew, midH, next);
    solution(midL, midW, sh, el, ew, midH, next);
    solution(sl, sw, midH, midL, midW, eh, next);
    solution(midL, sw, midH, el, midW, eh, next);
    solution(sl, midW, midH, midL, ew, eh, next);
    solution(midL, midW, midH, el, ew, eh, next);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> L >> W >> H >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        arr[a] = b;
    }
    solution(0, 0, 0, L, W, H, 20);
    std::cout << cnt << '\n';
}