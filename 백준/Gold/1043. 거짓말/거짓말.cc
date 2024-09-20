#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int parent[51];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return ;
    parent[y] = x;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    int trues;
    cin >> trues;
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    vector<int> trues_v(trues, 0);
    for (int i = 0; i < trues; i++)
        cin >> trues_v[i];
    for (int i = 0; i < trues - 1; i++)
        merge(trues_v[i], trues_v[i + 1]);
    vector<vector<int> > party(M, vector<int>());
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }
    if (trues == 0)
    {
        cout << M << '\n';
        return 0;
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < party[i].size() - 1; j++)
            merge(party[i][j], party[i][j + 1]);
    }
    int true_parent = find(trues_v[0]);
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        bool flag = true;
        for (int j = 0; j < party[i].size(); j++)
        {
            if (find(party[i][j]) == true_parent)
            {
                flag = false;
                break ;
            }
        }
        if (flag)
            cnt++;
    }
    cout << cnt << '\n';
}