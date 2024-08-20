#include <string>
#include <vector>

using namespace std;

vector<int> v[500001];
vector<int> ans;

int solution(std::vector<int> a) {
    int answer = -1;
    for (int i = 0; i < a.size(); i++)
        v[a[i]].push_back(i);
    for (int i = 0; i <= 500000; i++)
    {
        if (v[i].empty())
            continue ;
        int cnt = 0;
        int last_check = -10;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (last_check >= v[i][j])
                continue ;
            if (v[i][j] == 0 || last_check == v[i][j] - 1) // 해당 원소의 오른쪽을 파트너로
            {
                int next = v[i][j] + 1;
                while (next < a.size() && a[next] == i) // 해당 원소와 다른 원소가 나올떄까지 오른쪽으로
                    next++;
                if (next == a.size()) // 못찾은 경우
                    break ;
                last_check = next;
                cnt += 2;
            }
            else // 외에는 해당 원소의 왼쪽을 파트너로
            {
                last_check = v[i][j];
                cnt += 2;
            }
        }
        answer = max(answer, cnt);
    }
    return answer;
}