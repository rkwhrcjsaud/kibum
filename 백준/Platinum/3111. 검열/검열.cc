#include <iostream>
#include <deque>

std::string A, T;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> A >> T;
    std::deque<char> ld, rd;
    for (int left = 0, right = (int)T.size() - 1; left <= right;)
    {
        while (left <= right)
        {
            ld.push_back(T[left]);
            if (ld.size() >= A.size())
            {
                bool flag = true;
                for (int i = 0; i < (int)A.size(); i++)
                {
                    if (ld[ld.size() - A.size() + i] != A[i])
                    {
                        flag = false;
                        break ;
                    }
                }
                if (flag)
                {
                    for (int i = 0; i < (int)A.size(); i++)
                        ld.pop_back();
                    break ;
                }
            }
            left++;
        }
        left++;
        while (left <= right)
        {
            rd.push_front(T[right]);
            if (rd.size() >= A.size())
            {
                bool flag = true;
                for (int i = 0; i < (int)A.size(); i++)
                {
                    if (rd[i] != A[i])
                    {
                        flag = false;
                        break ;
                    }
                }
                if (flag)
                {
                    for (int i = 0; i < (int)A.size(); i++)
                        rd.pop_front();
                    break ;
                }
            }
            right--;
        }
        right--;
    }
    std::string result;
    for (int i = 0; i < (int)ld.size(); i++)
        result += ld[i];
    for (int i = 0; i < (int)rd.size(); i++)
        result += rd[i];
    while (result.find(A) != std::string::npos)
        result.replace(result.find(A), A.size(), "");
    std::cout << result << '\n';
}