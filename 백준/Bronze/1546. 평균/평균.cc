#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<double> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    double sum = 0;
    double m = v[v.size() - 1];
    for (int i = 0; i < N; i++)
    {
        v[i] = v[i] / m * 100;
        sum += v[i];
    }
    cout << sum / N << '\n';
}