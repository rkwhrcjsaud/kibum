#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> tmp(e + 1, 0);
    vector<int> ret(e + 1, 0);
    for (int i = 1; i <= e; ++i)
        for (int j = 1; j <= e / i; ++j)
            tmp[i * j]++;
    ret[e] = e;
    for (int i = e - 1; i > 0; --i)
    {
        if (tmp[i] >= tmp[ret[i + 1]])
            ret[i] = i;
        else
            ret[i] = ret[i + 1];
    }
    for (int i = 0; i < starts.size(); ++i)
        answer.push_back(ret[starts[i]]);
    return answer;
}