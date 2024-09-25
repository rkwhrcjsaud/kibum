#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

string str[3];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int idx = 0;
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> str[i];
        if (str[i].find("z") != string::npos)
            continue ;
        num = stoi(str[i]);
        idx = i;
    }
    for (int i = idx; i < 3; i++)
        num++;
    if (num % 3 == 0 && num % 5 == 0)
        cout << "FizzBuzz\n";
    else if (num % 3 == 0)
        cout << "Fizz\n";
    else if (num % 5 == 0)
        cout << "Buzz\n";
    else
        cout << num << '\n';
}