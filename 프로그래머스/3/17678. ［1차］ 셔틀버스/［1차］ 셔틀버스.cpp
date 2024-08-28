#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int N, M, T;

int tohash(const string &str)
{
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3));
    return h * 60 + m;
}

string unhash(int hash)
{
    int h = hash / 60;
    int m = hash % 60;
    string hh = to_string((h / 10)) + to_string(h % 10);
    string mm = to_string((m / 10)) + to_string(m % 10);
    return hh + ":" + mm;
}

bool sol(int mid, vector<int> vv)
{
    vv.push_back(mid);
    sort(vv.begin(), vv.end());
    for (int i = 540; i < 540 + N * T; i += T)
    {
        for (int j = 0; j < M && !vv.empty() && vv[0] <= i; j++)
            vv.erase(vv.begin());
    }
    if (vv.empty() || vv[0] > mid)
        return true;
    return false;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    N = n;
    T = t;
    M = m;
    int s = 0;
    int e = 3599;
    for (int i = 0; i < timetable.size(); i++)
        v.push_back(tohash(timetable[i]));
    sort(v.begin(), v.end());
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (sol(mid, v))
        {
            s = mid + 1;
            ans = max(ans, mid);
        }
        else
            e = mid - 1;
    }
    answer = unhash(ans);
    return answer;
}