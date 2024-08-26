#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int compare(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), compare);
    int cnt = 1;
    int l = routes[0][0], r = routes[0][1];
    for (int i = 1; i < routes.size(); i++)
    {
        if (r < routes[i][0])
        {
            l = routes[i][0];
            r = routes[i][1];
            cnt++;
        }
        else
        {
            l = routes[i][0];
            r = min(routes[i][1], r);
        }
    }
    answer = cnt;
    return answer;
}