#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int N, M;
vector<int> arr;
vector<pair<pair<int, int>, int> > edges;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> M;
	edges.resize(M);
	for (int i = 0; i < M; i++)
	{
		cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
		edges[i].first.first--;
		edges[i].first.second--;
	}
	map<vector<int>, int> dist;
	priority_queue<pair<int, vector<int> > > pq;
	dist[arr] = 0;
	pq.push(make_pair(0, arr));
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		vector<int> here = pq.top().second;
		pq.pop();
		for (int i = 0; i < M; i++)
		{
			swap(here[edges[i].first.first], here[edges[i].first.second]);
			if (!dist.count(here) || dist[here] > cost + edges[i].second)
			{
				dist[here] = cost + edges[i].second;
				pq.push(make_pair(-dist[here], here));
			}
			swap(here[edges[i].first.second], here[edges[i].first.first]);
		}
	}
	sort(arr.begin(), arr.end());
	if (dist.count(arr))
		cout << dist[arr] << '\n';
	else
		cout << -1 << '\n';
}