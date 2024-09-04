#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

class Trie {
    public:
    bool finish;
    int cnt;
    Trie *next[26];
    Trie() : finish(false), cnt(0) {
        memset(next, 0, sizeof(next));
    };
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i])
                delete next[i];
    };
    void insert(const char *key) {
        if (*key == '\0')
            finish = true;
        else {
            int curr = *key - 'a';
            if (next[curr] == NULL)
                next[curr] = new Trie();
            next[curr]->insert(key + 1);
            next[curr]->cnt++;
        }
    };
    int sol(const char *key) {
        if (*key == '\0')
            return 0;
        int curr = *key - 'a';
        if (next[curr]->cnt == 1)
            return 1;
        return (next[curr]->sol(key + 1) + 1);
    };
};

int solution(vector<string> words) {
    int answer = 0;
    Trie trie;
    for (int i = 0; i < words.size(); i++)
        trie.insert(words[i].c_str());
    for (int i = 0; i < words.size(); i++)
        answer += trie.sol(words[i].c_str());
    return answer;
}