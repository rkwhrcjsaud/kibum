#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 최단거리를 구한다.
// 2. 최단거리가 k보다 크거나, k와의 차가 홀수면 impossible

int N, M, R, C, K;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    M = m; N = n; R = r; C = c; K = k;
    int dist = abs(r - x) + abs(c - y);
    if (k < dist || abs(k - dist) % 2 == 1)
        return "impossible";
    while (dist | k)
    {
        if (x < r)
        {
            answer += "d";
            dist--;
            k--;
            x++;
        }
        else if (dist < k && x < n)
        {
            answer += "d";
            dist++;
            k--;
            x++;
        }
        else if (y > c)
        {
            answer += "l";
            dist--;
            k--;
            y--;
        }
        else if (dist < k && y > 1)
        {
            answer += "l";
            dist++;
            k--;
            y--;
        }
        else if (y < c)
        {
            answer += "r";
            dist--;
            k--;
            y++;
        }
        else if (dist < k && y < m)
        {
            answer += "r";
            dist++;
            k--;
            y++;
        }
        else if (x > r)
        {
            answer += "u";
            dist--;
            k--;
            x--;
        }
        else if (dist < k && x > 1)
        {
            answer += "u";
            dist++;
            k--;
            x--;
        }
    }
    return answer;
}