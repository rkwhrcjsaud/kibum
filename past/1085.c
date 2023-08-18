#include <stdio.h>

int main(void)
{
    int x, y, w, h;
    int xlen;
    int ylen;

    scanf("%d %d %d %d", &x, &y, &w, &h);
    if (w - x <= x)
        xlen = w - x;
    else
        xlen = x;
    if (h - y <= y)
        ylen = h - y;
    else
        ylen = y;
    if (ylen >= xlen)
        printf("%d", xlen);
    else
        printf("%d", ylen);
    return (0);
}