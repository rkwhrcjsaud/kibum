#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int R, C;
string s[1001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> s[i];
    int start = 0, end = R;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        set<string> st;
        bool flag = false;
        for (int i = 0; i < C; i++)
        {
            string tmp = "";
            for (int j = mid; j < R; j++)
                tmp += s[j][i];
            if (st.find(tmp) != st.end())
            {
                flag = true;
                break ;
            }
            st.insert(tmp);
        }
        if (flag)
            end = mid - 1;
        else
            start = mid + 1;
    }
    cout << start - 1 << '\n';
}