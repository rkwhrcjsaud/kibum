#include <iostream>

std::string str1, str2;
int arr1[26];
int arr2[26];
int front, back;
char ans[300000];

void apple(bool flag)
{
    if (flag)
    {
        int left = 0;
        while (arr1[left] == 0)
            left++;
        ans[front] = (char)(left + 'a');
        arr1[left]--;
        front++;
    }
    else
    {
        int right = 25;
        while (arr1[right] == 0)
            right--;
        ans[back] = (char)(right + 'a');
        arr1[right]--;
        back--;
    }
}

void cube(bool flag)
{
    if (flag)
    {
        int right = 25;
        while (arr2[right] == 0)
            right--;
        ans[front] = (char)(right + 'a');
        arr2[right]--;
        front++;
    }
    else
    {
        int left = 0;
        while (arr2[left] == 0)
            left++;
        ans[back] = (char)(left + 'a');
        arr2[left]--;
        back--;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str1 >> str2;
    int size = str1.size();
    front = 0, back = size - 1;
    for (int i = 0; i < size; i++)
        arr1[str1[i] - 'a']++;
    for (int i = 0; i < size; i++)
        arr2[str2[i] - 'a']++;
    int tmp = 25;
    for (int i = 0; i < size / 2; i++)
    {
        while (arr1[tmp] == 0)
            tmp--;
        arr1[tmp]--;
    }
    tmp = 0;
    for (int i = 0; i < (size + 1) / 2; i++)
    {
        while (arr2[tmp] == 0)
            tmp++;
        arr2[tmp]--;
    }
    int flag = true;
    for (int i = 0; i < size; i++)
    {
        if (flag)
        {
            int left = 0, right = 25;
            while (arr1[left] == 0)
                left++;
            while (arr2[right] == 0)
                right--;
            if (left >= right)
                flag = false;
        }
        if (i % 2 == 0)
            apple(flag);
        else
            cube(flag);
    }
    for (int j = 0; j < size; j++)
        std::cout << ans[j];
    std::cout << '\n';
}