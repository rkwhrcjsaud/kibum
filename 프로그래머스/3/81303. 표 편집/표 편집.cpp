#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct graph {
    int left;
    int right;
    bool isTrash;
};
vector<graph> v;
stack<int> trash;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    for (int i = 0; i < n; i++)
    {
        graph tmp;
        tmp.left = i - 1;
        tmp.right = i + 1;
        tmp.isTrash = false;
        v.push_back(tmp);
    }
    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i][0] == 'U') {
            int x = stoi(cmd[i].substr(2));
            while (x--)
                k = v[k].left;
        } else if (cmd[i][0] == 'D') {
            int x = stoi(cmd[i].substr(2));
            while (x--)
                k = v[k].right;
        } else if (cmd[i][0] == 'C') {
            v[k].isTrash = true;
            trash.push(k);
            int curL = v[k].left;
            int curR = v[k].right;
            if (curR != n)
                v[curR].left = curL;
            if (curL != -1)
                v[curL].right = curR;
            if (curR != n)
                k = v[k].right;
            else
                k = v[k].left;
        } else if (cmd[i][0] == 'Z') {
            int tmp = trash.top();
            trash.pop();
            int curL = v[tmp].left;
            int curR = v[tmp].right;
            if (curL != -1)
                v[curL].right = tmp;
            if (curR != n)
                v[curR].left = tmp;
            v[tmp].isTrash = false;
        }
    }
    for (int i = 0; i < n; i++)
        answer += v[i].isTrash ? "X" : "O";
    return answer;
}