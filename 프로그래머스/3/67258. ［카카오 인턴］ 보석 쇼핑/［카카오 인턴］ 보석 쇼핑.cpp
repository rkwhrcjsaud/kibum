#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> gem;
int N;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    N = gems.size();
    int total = 0;
    int minL = N, minR = N;
    int l = 0, r = 0;
    for (int i = 0; i < N; i++)
    {
        gem[gems[i]]++;
        if (gem[gems[i]] == 1)
        {
            total++;
            r = i;
            minL = l;
            minR = i;
        }
        else
        {
            r = i;
            for (int j = l; j <= i; j++)
            {
                if (gem[gems[j]] > 1)
                    gem[gems[j]]--;
                else
                {
                    l = j;
                    if (r - l < minR - minL)
                    {
                        minR = r;
                        minL = l;
                    }
                    break ;
                }
            }
        }
    }
    answer[0] = minL + 1;
    answer[1] = minR + 1;
    return answer;
}