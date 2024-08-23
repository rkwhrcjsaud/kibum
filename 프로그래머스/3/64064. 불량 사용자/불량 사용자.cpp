#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <set>

using namespace std;
bool visited[8] = {false, };
set<set<string>> banned_list;

bool backTracking(string &s1, string &s2)
{
    if (s1.size() != s2.size())
        return false;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '*' || s2[i] == '*')
            continue ;
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

void dfs(int depth, vector<string> &user_id, vector<string> &banned_id, set<string> &str)
{
    if (depth == banned_id.size())
    {
        banned_list.insert(str);
        return ;
    }
    for (int i = 0; i < user_id.size(); i++)
    {
        if (visited[i])
            continue ;
        if (!backTracking(user_id[i], banned_id[depth]))
            continue ;
        visited[i] = true;
        str.insert(user_id[i]);
        dfs(depth + 1, user_id, banned_id, str);
        str.erase(user_id[i]);
        visited[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    set<string> tmp;
    dfs(0, user_id, banned_id, tmp);
    answer = banned_list.size();
    return answer;
}