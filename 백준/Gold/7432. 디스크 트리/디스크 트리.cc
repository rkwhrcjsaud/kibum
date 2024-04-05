#include <iostream>
#include <map>

int N;
std::string str;

class Trie
{
    public:
        Trie *next[130];
        bool finish;
        bool directory;
        Trie() : finish(false), directory(false)
        {
            for (int i = 0; i < 130; i++)
                next[i] = NULL;
        }
        ~Trie()
        {
            for (int i = 0; i < 130; i++)
                if (next[i])
                    delete next[i];
        }
        void insert(const char *key)
        {
            if (*key == '\0')
            {
                finish = true;
                return ;
            }
            int idx = *key;
            if (*key == '\\')
            {
                finish = false;
                directory = true;
            }
            if (!next[idx])
                next[idx] = new Trie();
            next[idx]->insert(key + 1);
        }
        Trie *find(const char *key)
        {
            if (*key == '\0')
                return this;
            int idx = *key;
            if (!next[idx])
                return NULL;
            return next[idx]->find(key + 1);
        }
};

void dfs(Trie *node, std::string str, int depth)
{
    if (node->finish || node->directory)
    {
        for (int i = 0; i < depth; i++)
            std::cout << " ";
        std::cout << str << '\n';
    }
    if (node->next['\\'])
        dfs(node->next['\\'], "", depth + 1);
    for (int i = 0; i < 130; i++)
    {
        if (i == '\\')
            continue ;
        if (node->next[i])
            dfs(node->next[i], str + (char)i, depth);
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    Trie *root = new Trie();
    for (int i = 0; i < N; ++i)
    {
        std::cin >> str;
        root->insert(str.c_str());
    }
    str = "";
    dfs(root, str, 0);
    delete root;
}