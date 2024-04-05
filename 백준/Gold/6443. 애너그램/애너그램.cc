#include <iostream>

int T;
std::string str;
std::string s = "";
int arr[26];

void solve(void)
{
    if (s.size() == str.size())
    {
        std::cout << s << '\n';
        return ;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0)
        {
            arr[i]--;
            s += (char)(i + 'a');
            solve();
            s.pop_back();
            arr[i]++;
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> str;
        for (int i = 0; i < 26; i++)
            arr[i] = 0;
        for (int i = 0; i < str.size(); i++)
            arr[str[i] - 'a']++;
        solve();
    }
}