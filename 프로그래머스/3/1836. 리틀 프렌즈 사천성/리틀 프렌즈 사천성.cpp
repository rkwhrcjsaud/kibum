#include <string>
#include <vector>

using namespace std;
struct Friend {
    int y1 = -1, x1 = -1, y2 = -1, x2 = -1;
    bool isDelete = true;
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    Friend arr[27];
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.' || board[i][j] == '*')
                continue ;
            Friend &tmp = arr[board[i][j] - 'A'];
            if (tmp.y1 != -1)
            {
                if (tmp.x1 > j) // 항상 y1, x1은 y2, x2보다 왼쪽에 위치함
                {
                    tmp.y2 = tmp.y1;
                    tmp.x2 = tmp.x1;
                    tmp.y1 = i;
                    tmp.x1 = j;
                }
                else
                {
                    tmp.y2 = i;
                    tmp.x2 = j;
                }
            }
            else
            {
                tmp.y1 = i;
                tmp.x1 = j;
                tmp.isDelete = false;
                cnt++;
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (arr[j].isDelete)
                continue ;
            bool up = true;
            bool down = true;
            for (int k = min(arr[j].x1, arr[j].x2); k <= max(arr[j].x1, arr[j].x2); k++)
            {
                if (board[min(arr[j].y1, arr[j].y2)][k] != '.' && board[min(arr[j].y1, arr[j].y2)][k] != j + 'A')
                    up = false;
                if (board[max(arr[j].y1, arr[j].y2)][k] != '.' && board[max(arr[j].y1, arr[j].y2)][k] != j + 'A')
                    down = false;
            }
            bool left = true;
            bool right = true;
            for (int k = min(arr[j].y1, arr[j].y2); k <= max(arr[j].y1, arr[j].y2); k++)
            {
                if (board[k][min(arr[j].x1, arr[j].x2)] != '.' && board[k][min(arr[j].x1, arr[j].x2)] != j + 'A')
                    left = false;
                if (board[k][max(arr[j].x1, arr[j].x2)] != '.' && board[k][max(arr[j].x1, arr[j].x2)] != j + 'A')
                    right = false;
            }
            if (arr[j].y1 <= arr[j].y2 && ((up && right) || (down && left)))
            {
                answer.push_back(j + 'A');
                board[arr[j].y1][arr[j].x1] = '.';
                board[arr[j].y2][arr[j].x2] = '.';
                arr[j].isDelete = true;
                break ;
            }
            if (arr[j].y1 >= arr[j].y2 && ((up && left) || (down && right)))
            {
                answer.push_back(j + 'A');
                board[arr[j].y1][arr[j].x1] = '.';
                board[arr[j].y2][arr[j].x2] = '.';
                arr[j].isDelete = true;
                break ;
            }
        }
    }
    if (answer.size() != cnt)
        return "IMPOSSIBLE";
    return answer;
}