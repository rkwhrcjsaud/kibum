#include <iostream>
#include <map>

int N;
std::string str;

class Trie
{
    public:
        Trie *next[26];
        int cnt;
        bool finish;
        bool directory;
        Trie() : cnt(0), finish(false), directory(false)
        {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
        ~Trie()
        {
            for (int i = 0; i < 26; i++)
                if (next[i])
                    delete next[i];
        }
        void insert(const char *key, std::string s, bool flag)
        {
            if (*key == '\0')
            {
                finish = true;
                cnt++;
                if (flag)
                {
                    if (cnt > 1)
                        std::cout << (std::string)s + std::to_string(cnt) << '\n';
                    else
                        std::cout << (std::string)s << '\n';
                }
                return ;
            }
            int idx = *key - 'a';
            if (!next[idx])
            {
                if (flag)
                {
                    s += *key;
                    std::cout << (std::string)s << '\n';
                }
                flag = false;
                next[idx] = new Trie();
            }
            next[idx]->insert(key + 1, s + *key, flag);
        }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    Trie *root = new Trie();
    for (int i = 0; i < N; ++i)
    {
        std::cin >> str;
        root->insert(str.c_str(), "", true);
    }
}