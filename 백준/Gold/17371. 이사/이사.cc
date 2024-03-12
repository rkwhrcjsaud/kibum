#include <iostream>
#include <cmath>

double N;
struct Point
{
    double x;
    double y;
};
Point p[1010];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        double x, y;
        std::cin >> x >> y;
        p[i].x = x;
        p[i].y = y;
    }
    double min = 1000000000;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        double max = 0;
        int idx = 0;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            double tmp = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
            if (max < tmp)
            {
                max = tmp;
                idx = i;
            }
        }
        if (min > max)
        {
            min = max;
            ans = idx;
        }
    }
    std::cout << p[ans].x << ' ' << p[ans].y << '\n';
}