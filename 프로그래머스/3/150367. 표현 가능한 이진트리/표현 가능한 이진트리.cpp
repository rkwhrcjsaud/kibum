#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

int isAllZero(string &bit, ll s, ll e)
{
    for (ll i = s; i <= e; i++)
    {
        if (bit[i] == '1')
            return 0;
    }
    return 1;
}

string hexToDec(long long num) {
    string ret = "";
    while (num) {
        ret = to_string(num % 2) + ret;
        num /= 2;
    }
    return ret;
}
 
string changeToFullDec(string str) {
    string ret = str;
    int idx = 2;
    while (true) {
        if (str.length() <= idx - 1) break;
        idx *= 2;
    }
    for (int i = 0; i < idx - 1 - str.length(); i++) ret = "0" + ret;
    return ret;
}

int isAble(string &bit, ll s, ll e)
{
    if (isAllZero(bit, s, e))
        return 1;
    if (s == e)
        return 1;
    ll mid = (s + e) / 2;
    if (bit[mid] == '0')
        return 0;
    return (isAble(bit, s, mid - 1) & isAble(bit, mid + 1, e));
}

int sol(ll num)
{
    if (num == 0)
        return 0;
    string bit = hexToDec(num);
    bit = changeToFullDec(bit);
    return isAble(bit, 0, bit.size() - 1);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++)
        answer.push_back(sol(numbers[i]));
    return answer;
}
