#include <string>
#include <vector>

using namespace std;
typedef long long ll;
vector<ll> max_nums;
vector<ll> min_nums;

long long solution(vector<int> sequence) {
    long long answer = 0;
    for (int i = 0; i < sequence.size(); i++)
        sequence[i] *= (1 - (2 * (i % 2 == 0)));
    ll min_num = sequence[0];
    ll max_num = sequence[0];
    max_nums.push_back(sequence[0]);
    min_nums.push_back(sequence[0]);
    for (int i = 1; i < sequence.size(); i++)
    {
        ll max_tmp = max_nums[i - 1] + sequence[i];
        ll min_tmp = min_nums[i - 1] + sequence[i];
        ll max_val = max(max_tmp, (ll)sequence[i]);
        ll min_val = min(min_tmp, (ll)sequence[i]);
        max_nums.push_back(max_val);
        min_nums.push_back(min_val);
        if (max_num < max_val)
            max_num = max_val;
        if (min_num > min_val)
            min_num = min_val;
    }
    answer = abs(min_num) > abs(max_num) ? abs(min_num) : abs(max_num);
    return answer;
}