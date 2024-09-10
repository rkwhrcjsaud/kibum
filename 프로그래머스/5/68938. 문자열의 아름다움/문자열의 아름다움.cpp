#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef long long ll;

long long solution(string s) {
    unordered_map<char, unordered_map<ll, ll> > m;
    ll n = s.size();
    int i = 0;
    while (i < n)
    {
        char c = s[i];
        int cnt = 0;
        while (i < n && c == s[i])
        {
            cnt++;
            i++;
        }
        m[c][cnt]++;
    }
    
    ll unpretty = (n - 1) * n * (n + 1) / 6;
    for (unordered_map<char, unordered_map<ll, ll> >::iterator it = m.begin(); it != m.end(); it++)
    {
        unordered_map<ll, ll> &tmp = it->second;
        ll total = 0;
        ll side = 0;
        ll max_len = 0;
        for (unordered_map<ll, ll>::iterator it2 = tmp.begin(); it2 != tmp.end(); it2++)
        {
            total += it2->first * it2->second;
            side += it2->second;
            max_len = max(max_len, it2->first);
        }
        for (int j = 1; j <= max_len; j++)
        {
            unpretty -= total * (total - 1) / 2;
            total -= side;
            if (tmp.count(j))
                side -= tmp[j];
        }
    }
    return unpretty;
}