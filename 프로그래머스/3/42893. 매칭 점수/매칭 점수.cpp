#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
struct Page {
    string url;
    vector<string> links;
    int default_point = 0;
    string body = "";
};

Page p[21];
vector<pair<string, double>> linkPoint;
double point[21] = {0, };

void calc_default_point(int idx, string &body, string &word)
{
    regex word_pattern("[a-z]+");
    auto begin = sregex_iterator(body.begin(), body.end(), word_pattern);
    auto end = sregex_iterator();
    
    for (sregex_iterator i = begin; i != end; i++)
    {
        smatch match = *i;
        if (match.str(0) == word)
            p[idx].default_point++;
    }
    linkPoint.push_back(make_pair(p[idx].url, (double)p[idx].default_point / p[idx].links.size()));
}

void parse(int idx, vector<string> &pages)
{
    string &html = pages[idx];
    regex content_pattern("<meta property=\"og:url\" content=\"https://(\\S*)\"");
    auto begin1 = sregex_iterator(html.begin(), html.end(), content_pattern);
    auto end1 = sregex_iterator();
    
    for (sregex_iterator i = begin1; i != end1; ++i) {
        smatch match = *i;
        p[idx].url = match.str(1);
    }
    
    regex href_pattern("<a href=\"https://(\\S*)\"");
    auto begin2 = sregex_iterator(html.begin(), html.end(), href_pattern);
    auto end2 = sregex_iterator();

    for (sregex_iterator i = begin2; i != end2; ++i) {
        smatch match = *i;
        string url = match.str(1);
        p[idx].links.push_back(url);
    }
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    for (int i = 0; i < pages.size(); i++)
    {
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        parse(i, pages);
    }
    for (int i = 0; i < pages.size(); i++)
        calc_default_point(i, pages[i], word);
    double max_point = 0;
    for (int i = 0; i < pages.size(); i++)
    {
        point[i] += p[i].default_point;
        for (int j = 0; j < p[i].links.size(); j++)
        {
            for (int k = 0; k < linkPoint.size(); k++)
            {
                if (p[i].url == linkPoint[k].first)
                {
                    for (int l = 0; l < pages.size(); l++)
                    {
                        if (p[l].url == p[i].links[j])
                        {
                            point[l] += linkPoint[k].second;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < pages.size(); i++)
    {
        if (max_point < point[i])
        {
            answer = i;
            max_point = point[i];
        }
    }
    return answer;
}