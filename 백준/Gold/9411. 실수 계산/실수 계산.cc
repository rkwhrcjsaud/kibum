#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>

using namespace std;

// 최대 30자리 실수를 저장하는 구조체
struct BigFloat {
    int digits[30] = {0};  // 30자리 숫자 저장
    int decpt = 0;         // 소수점 위치
    int sign = 1;          // 부호 (+1 또는 -1)

    // 소수점을 맞추기 위해 숫자들을 shift하는 함수
    void shiftRight(int places) {
        for (int i = 29; i >= places; --i) {
            digits[i] = digits[i - places];
        }
        for (int i = 0; i < places; ++i) {
            digits[i] = 0;
        }
        decpt += places;
    }

    // 출력을 위한 함수
    void print() {
        string str = "";
        for (int i = 0; i < 30; i++) {
            if (i == decpt) str += ".";
            str += to_string(digits[i]);
        }
        // 불필요한 뒤의 0 제거
        while (str.back() == '0') {
            str.pop_back();
        }
        // 불필요한 앞의 0 제거
        while (str.front() == '0' && str[1] != '.') {
            str = str.substr(1);
        }
        // 소수점 뒤의 . 도 제거
        if (str.back() == '.') {
            str.pop_back();
        }
        // 모두 제거되었을 경우 0으로 처리
        if (str.empty()) {
            str = "0";
        }
        // 부호 처리
        if (sign == -1) {
            str = "-" + str;
        }
        cout << str;
        cout << endl;
    }
};

// 두 수 중 어느 것이 더 큰지 비교하는 함수 (절대값 비교)
bool isAbsGreater(const BigFloat &a, const BigFloat &b) {
    // 자릿수가 다르면 자릿수 큰 쪽이 더 큼
    if (a.decpt != b.decpt) {
        return a.decpt > b.decpt;
    }

    // 자릿수가 같으면 각 자리 비교
    for (int i = 0; i < 30; ++i) {
        if (a.digits[i] != b.digits[i]) {
            return a.digits[i] > b.digits[i];
        }
    }
    return false;  // 같으면 false
}

// 두 BigFloat 실수의 뺄셈을 구현하는 함수
BigFloat subtractBigFloat(BigFloat a, BigFloat b) {
    BigFloat result;

    // 자릿수 맞추기
    if (a.decpt > b.decpt) {
        b.shiftRight(a.decpt - b.decpt);
    } else if (a.decpt < b.decpt) {
        a.shiftRight(b.decpt - a.decpt);
    }

    // 절대값 비교해서 큰 쪽에서 작은 쪽을 빼기
    bool aIsGreater = isAbsGreater(a, b);
    BigFloat bigger = aIsGreater ? a : b;
    BigFloat smaller = aIsGreater ? b : a;
    result.sign = aIsGreater ? a.sign : -a.sign;

    // 자리 내림 처리하며 뺄셈 수행
    int borrow = 0;
    for (int i = 29; i >= 0; --i) {
        int diff = bigger.digits[i] - smaller.digits[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits[i] = diff;
    }

    // 소수점 위치는 더 큰 수와 동일
    result.decpt = bigger.decpt;

    return result;
}

// 두 실수의 합을 구하는 함수
BigFloat addBigFloat(const BigFloat &a, const BigFloat &b) {
    BigFloat result;

    // 자릿수를 맞추기 위해 소수점 위치 조정
    BigFloat x = a, y = b;
    if (x.decpt > y.decpt) {
        y.shiftRight(x.decpt - y.decpt); // y의 소수점을 x에 맞춤
    } else if (x.decpt < y.decpt) {
        x.shiftRight(y.decpt - x.decpt); // x의 소수점을 y에 맞춤
    }

    // 부호가 다를 경우에는 뺄셈으로 전환해야 함 (추후 구현)
    if (x.sign != y.sign) {
        y.sign *= -1;
        return subtractBigFloat(x, y);
    }

    // 자릿수별로 덧셈 수행 (일단 부호가 같은 경우만 처리)
    int carry = 0;
    for (int i = 29; i >= 0; --i) {
        int sum = x.digits[i] + y.digits[i] + carry;
        result.digits[i] = sum % 10;  // 자릿수
        carry = sum / 10;             // 자리 올림
    }

    // 자리 올림이 남을 경우 소수점 위치 조정
    if (carry > 0) {
        for (int i = 29; i > 0; --i) {
            result.digits[i] = result.digits[i - 1];
        }
        result.digits[0] = carry;
        result.decpt++;
    } else {
        result.decpt = x.decpt; // 소수점 위치 그대로
    }

    result.sign = x.sign;  // 결과의 부호는 동일함
    return result;
}

// 문자열을 BigFloat 구조체로 변환하는 함수
BigFloat stringToBigFloat(const string &str) {
    BigFloat result;
    string num = str;

    // 부호 확인
    if (num[0] == '-') {
        result.sign = -1;
        num = num.substr(1);  // 부호 제거
    } else if (num[0] == '+') {
        result.sign = 1;
        num = num.substr(1);  // 부호 제거
    }

    // 소수점 위치 확인
    size_t dotPos = num.find('.');
    if (dotPos == string::npos) {
        dotPos = num.size();  // 소수점이 없는 경우
    }

    // 정수부와 소수부 분리
    string integerPart = num.substr(0, dotPos);
    string fractionalPart = (dotPos != num.size()) ? num.substr(dotPos + 1) : "";

    // 소수점 위치 설정
    result.decpt = integerPart.size();

    // 정수부 처리
    int index = 0;
    for (char ch : integerPart) {
        if (index >= 30) break;  // 최대 30자리만 처리
        result.digits[index++] = ch - '0';
    }

    // 소수부 처리
    for (char ch : fractionalPart) {
        if (index >= 30) break;
        result.digits[index++] = ch - '0';
    }

    return result;
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        BigFloat ret;
        while (1)
        {
            string s;
            cin >> s;
            if (s == "0")
                break ;
            BigFloat a = stringToBigFloat(s);
            ret = addBigFloat(ret, a);
        }
        ret.print();
    }
}