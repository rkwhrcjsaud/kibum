#include <iostream>
#include <stack>

std::string str;
int i;

int calc(void)
{
    std::stack<int> s;
    int last = 0;
    while (i < (int)str.size())
    {
        if (str[i] == ')')
        {
            i++;
            int sum = 0;
            for (; !s.empty(); s.pop())
                sum += s.top();
            return sum;
        }
        if (str[i] == '(')
        {
            i++;
            s.pop();
            s.push(last * calc());
        }
        if (isdigit(str[i]))
        {
            s.push(1);
            last = str[i] - '0';
            i++;
        }
    }
    int sum = 0;
    for (; !s.empty(); s.pop())
        sum += s.top();
    return sum;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    std::cout << calc() << '\n';
}