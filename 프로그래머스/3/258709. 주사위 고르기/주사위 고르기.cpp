#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

// 2 <= n <= 10, n은 2의 배수
// dice[i]의 길이 = 6
// 1 <= dice[i]의 원소 <= 100
// 1. A와 B가 가져갈 주사위를 둘로 나눈다.
// 2. B가 가진 주사위로 나올 수 있는 모든 점수를 담은 벡터를 반환받는다.
// 3. A가 가진 주사위로 나올 수 있는 모든 점수에 대해서 그 점수보다 낮은 B벡터의 수를 더한다
int n;
vector<int> arr[1025];

vector<int> makeArr(int bit, vector<vector<int>> &dice)
{
    if (!arr[bit].empty())
        return arr[bit];
    vector<int> &v = arr[bit];
    for (int i = 0; i < n; i++)
    {
        if (bit & (1 << i))
        {
            vector<int> tmp = makeArr(bit ^ (1 << i), dice);
            for (int j = 0; j < tmp.size(); j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    v.push_back(tmp[j] + dice[i][k]);
                }
            }
            return v; 
        }
    }
    return arr[bit];
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    n = dice.size();
    arr[0].push_back(0);
    int win = 0;
    int winbit = 0;
    
    for (int i = 0; i < (1 << n); i++)
    {
        bitset<10> bit(i);
        if (bit.count() != (n / 2))
            continue;
        int j = ((1 << n) - 1) ^ i;
        
        if (arr[i].empty())
            makeArr(i, dice);
        if (arr[j].empty())
            makeArr(j, dice);
        
        sort(arr[i].begin(), arr[i].end());
        sort(arr[j].begin(), arr[j].end());
        
        int cnt = 0;
        for (int k = 0; k < arr[i].size(); k++)
        {
            int tmp = lower_bound(arr[j].begin(), \
                                  arr[j].end(), arr[i][k]) - arr[j].begin();
            cnt += tmp - 1;
        }
        if (win < cnt)
        {
            win = cnt;
            winbit = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (winbit & (1 << i))
            answer.push_back(i + 1);
    }
    return answer;
}