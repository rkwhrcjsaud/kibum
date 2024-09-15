#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int S, T;
struct Point {
    int x, y;
};

struct Line {
    Point p1, p2;
};

vector<Line> s;

int ccw(Point a, Point b, Point c)
{
    int op = a.x * b.y + b.x * c.y + c.x * a.y;
    op -= (a.y * b.x + b.y * c.x + c.y * a.x);
    if (op > 0)
        return 1;
    else if (op == 0)
        return 0;
    else
        return -1;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> S;
    for (int i = 0; i < S; i++)
    {
        Line l;
        cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y;
        s.push_back(l);
    }
    cin >> T;
    while (T--)
    {
        Line l;
        cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y;
        int cnt = 0;
        for (int i = 0; i < S; i++)
        {
            // vector<Line> s는 끝이 없는 직선이므로 s[i]의 기준으로만 생각하면 된다.
            int a = ccw(s[i].p1, s[i].p2, l.p1) * ccw(s[i].p1, s[i].p2, l.p2);
            if (a < 0)
                cnt++;
        }
        if (cnt % 2 == 0)
            cout << "same\n";
        else
            cout << "different\n";
    }
}