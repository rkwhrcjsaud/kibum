#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

vector<int> v;

long long solution(vector<vector<int> > land, int P, int Q) {
    ll answer = 1e18;
    ll n = land.size();
    ll pre = 0, pos = 0;
    ll preblock, postblock;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v.push_back(land[i][j]);
            pos += land[i][j];
        }
    }
    sort(v.begin(), v.end());
    if (n == 1 || v[0] == v[v.size() - 1])
        return 0;

    for (int i = 0; i < v.size(); ++i) {
        if (i > 0)
            pre += v[i - 1];
        pos -= v[i];
        preblock = i * v[i] - pre;
        postblock = pos - (v.size() - 1 - i) * v[i];

        answer = min(answer, preblock * P + postblock * Q);
    }
    return answer;
}