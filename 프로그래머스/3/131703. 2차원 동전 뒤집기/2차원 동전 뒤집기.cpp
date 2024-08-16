#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = -1;
    M = beginning.size();
    N = beginning[0].size();
    for (int i = 0; i < (1 << M); i++) // n번째 줄을 뒤집었으면 해당 bit가 1
    {
        int cnt = 0;
        vector<vector<int>> tmp = beginning;
        for (int j = 0; j < M; j++)
        {
            if (i & (1 << j))
            {
                cnt++;
                for (int k = 0; k < N; k++)
                    tmp[j][k] = tmp[j][k] ? 0 : 1;
            }
        }
        
        // 모든 세로줄에 대해서 모두 같은모양이거나 다른모양이어야 클리어
        bool clear = true;
        for (int j = 0; j < N; j++)
        {
            bool same;
            if (tmp[0][j] == target[0][j])
                same = true;
            else
                same = false;
            for (int k = 1; k < M; k++)
            {
                if ( (tmp[k][j] == target[k][j] && same == false) || \
                    (tmp[k][j] != target[k][j] && same == true) )
                {
                    clear = false;
                    break ;
                }
            }
            if (!same)
                cnt++;
        }
        if (clear && (answer > cnt || answer == -1))
            answer = cnt;
    }
    return answer;
}