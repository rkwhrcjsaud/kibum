#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <queue>

using namespace std;
map<string, int> genreToNum;

struct compare {
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    };
};

struct Genre {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    int total;
};

int comp(Genre &a, Genre &b)
{
    return a.total > b.total;
}

vector<Genre> v;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for (int i = 0; i < genres.size(); i++)
    {
        if (genreToNum.find(genres[i]) == genreToNum.end())
        {
            genreToNum[genres[i]] = v.size();
            Genre tmp;
            tmp.pq.push(make_pair(plays[i], i));
            tmp.total = plays[i];
            v.push_back(tmp);
        }
        else
        {
            v[genreToNum[genres[i]]].total += plays[i];
            v[genreToNum[genres[i]]].pq.push(make_pair(plays[i], i));
        }
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < 2 && !v[i].pq.empty(); j++)
        {
            answer.push_back(v[i].pq.top().second);
            v[i].pq.pop();
        }
    }
    return answer;
}