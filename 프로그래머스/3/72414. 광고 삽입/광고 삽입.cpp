#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
typedef long long ll;
vector<ll> v;

int timeTrans(int h, int m, int s)
{
    return h * 60 * 60 + m * 60 + s;
}

int parseTime(string s)
{
    return timeTrans(stoi(s.substr(0, 2)), stoi(s.substr(3, 2)), stoi(s.substr(6, 2)));
}

string stringTrans(int t)
{
    int h = t / 3600;
    t %= 3600;
    int m = t / 60;
    t %= 60;
    int s = t;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << h << ":"
       << std::setw(2) << std::setfill('0') << m << ":"
       << std::setw(2) << std::setfill('0') << s;
    return ss.str();
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int total = parseTime(play_time);
    v.resize(total + 1, 0);
    for (int i = 0; i < logs.size(); i++)
    {
        int startTime = parseTime(logs[i].substr(0, 8));
        int endTime = parseTime(logs[i].substr(9, 8));
        v[startTime] += 1;
        v[endTime] -= 1;
    }
    for (int i = 1; i <= total; i++)
        v[i] += v[i - 1];
    for (int i = 1; i <= total; i++)
        v[i] += v[i - 1];
    int adv = parseTime(adv_time);
    ll maxTime = -1;
    int ans = -1;
    for (int i = 0; i + adv <= total + 1; i++)
    {
        int endTime = i + adv;
        ll tmp = v[endTime - 1];
        if (i > 0)
            tmp -= v[i - 1];
        if (tmp > maxTime)
        {
            maxTime = tmp;
            ans = i;
        }
    }
    return answer = stringTrans(ans);
}