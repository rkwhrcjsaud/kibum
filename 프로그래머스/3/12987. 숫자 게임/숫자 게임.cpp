#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int ans = 0;

void sol(int idxA, int idxB, vector<int> &A, vector<int> &B)
{
    if (idxA == A.size() || idxB == B.size())
        return ;
    if (A[idxA] < B[idxB])
    {
        ans++;
        sol(idxA + 1, idxB + 1, A, B);
    }
    else
        sol(idxA, idxB + 1, A, B);
}

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sol(0, 0, A, B);
    return ans;
}