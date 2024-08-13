#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int a = scores[0][0];
    int b = scores[0][1];
    for (int i = 1; i < scores.size(); i++)
    {
        int aa = scores[i][0];
        int bb = scores[i][1];
        if (aa > a && bb > b)
            return -1;
        if (aa + bb > a + b)
        {
            answer++;
            for (int j = 1; j < scores.size(); j++)
            {
                int aaa = scores[j][0];
                int bbb = scores[j][1];
                if (aaa > aa && bbb > bb)
                {
                    answer--;
                    break ;
                }
            }
        }
    }
    return answer;
}