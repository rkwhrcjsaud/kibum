#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
string cell[51][51];
pair<int ,int> parent[51][51];

pair<int, int> unionFind(pair<int, int> a)
{
    if (parent[a.first][a.second] == a)
        return a;
    return parent[a.first][a.second] = unionFind(parent[a.first][a.second]);
}

void unionMerge(pair<int, int> a, pair<int, int> b)
{
    pair<int, int> aParent = unionFind(a);
    pair<int, int> bParent = unionFind(b);
    parent[aParent.first][aParent.second] = make_pair(bParent.first, bParent.second);
}

void updateRC(int r, int c, string value)
{
    pair<int, int> root = unionFind(make_pair(r, c));
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            if (unionFind(make_pair(i, j)) == root)
                cell[i][j] = value;
        }
    }
}

void updateValue(string value1, string value2)
{
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            if (cell[i][j] == value1)
                cell[i][j] = value2;
        }
    }
}

void merge(int r1, int c1, int r2, int c2)
{
    pair<int, int> root1 = unionFind(make_pair(r1, c1));
    pair<int, int> root2 = unionFind(make_pair(r2, c2));
    if (cell[root1.first][root1.second].empty())
        updateRC(r1, c1, cell[root2.first][root2.second]);
    else
        updateRC(r2, c2, cell[root1.first][root1.second]);
    unionMerge(root1, root2);
}

void unmerge(int r, int c)
{
    pair<int, int> root = unionFind(make_pair(r, c));
    string value = cell[root.first][root.second];
    vector<pair<int, int>> v;
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            if (unionFind(make_pair(i, j)) == root)
                v.push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cell[v[i].first][v[i].second] = "";
        parent[v[i].first][v[i].second] = make_pair(v[i].first, v[i].second);
    }
    cell[r][c] = value;
}

string printValue(int r, int c)
{
    pair<int, int> root = unionFind(make_pair(r, c));
    string answer = cell[root.first][root.second];
    if (answer.empty())
        answer = "EMPTY";
    return answer;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for (int i = 0; i < 51; i++)
        for (int j = 0; j < 51; j++)
            parent[i][j] = make_pair(i, j);
    for (int i = 0; i < commands.size(); i++)
    {
        stringstream ss(commands[i]);
        string command, value;
        int r, c;
        ss >> command;
        if (command == "PRINT")
        {
            ss >> r >> c;
            answer.push_back(printValue(r, c));
        }
        else if (command == "UPDATE")
        {
            string a, b, c;
            ss >> a >> b >> c;
            if (c.empty())
                updateValue(a, b);
            else
                updateRC(stoi(a), stoi(b), c);
        }
        else if (command == "MERGE")
        {
            int r2, c2;
            ss >> r >> c >> r2 >> c2;
            merge(r, c, r2, c2);
        }
        else if (command == "UNMERGE")
        {
            ss >> r >> c;
            unmerge(r, c);
        }
    }
    return answer;
}