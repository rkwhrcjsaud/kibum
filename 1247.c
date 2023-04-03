#include <stdio.h>
#include <limits.h>

typedef signed long long int ll;

int nbrlen(ll nbr)
{
    int i;

    i = 0;
    while (nbr)
    {
        nbr /= 10;
        i++;
    }
    return (i);
}

int main(void)
{
    int     n;
    int     i;
    int     over[3] = {0};
    ll      cur;
    ll      sum[3] = {0};

    i = 0;
    while (i < 3)
    {
        scanf("%d", &n);
        while (n > 0)
        {
            cur = 0;
            scanf("%lld", &cur);
            if (cur > 0)
                if (sum[i] > LLONG_MAX - cur)
                    over[i]++;
            if (cur < 0)
                if (sum[i] < LLONG_MIN - cur)
                    over[i]--;
            sum[i] += cur;
            n--;
        }
        i++;
    }
    i = 0;
    while (i < 3)
    {
        if (over[i] > 0)
            printf("%c\n", '+');
        else if (over[i] < 0)
            printf("%c\n", '-');
        else if (sum[i] < 0)
            printf("%c\n", '-');
        else if (sum[i] == 0)
            printf("%c\n", '0');
        else
            printf("%c\n", '+');
        i++;
    }
    return (0);
}