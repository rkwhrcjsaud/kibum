#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

double N;
vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    if (N == 0)
    {
        cout << "0\n";
        return (0);
    }
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int tmp = round(N * 0.15);
    double sum = 0;
    for (int i = tmp; i < N - tmp; i++)
        sum += v[i];
    cout << round(sum / (N - 2 * tmp)) << '\n';
}