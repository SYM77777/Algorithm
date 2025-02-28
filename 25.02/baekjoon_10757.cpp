#include <iostream>
#include <cstring>  // strlen() 사용
#include <vector>

using namespace std;

char A[10002];
char B[10002];

void input() {
    cin >> A >> B;
}

void cal() {
    int lenA = strlen(A);
    int lenB = strlen(B);
    int carry = 0;  // 자리 올림
    vector<int> result;

    int i = lenA - 1, j = lenB - 1;

    // 뒤에서부터 더하기
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;  // 이전 자리 올림 반영

        if (i >= 0) sum += A[i--] - '0';
        if (j >= 0) sum += B[j--] - '0';

        result.push_back(sum % 10);  // 현재 자리 숫자 저장
        carry = sum / 10;  // 자리 올림 업데이트
    }

    // 결과 출력 (뒤집어서 출력해야 함)
    for (int k = result.size() - 1; k >= 0; k--) {
        cout << result[k];
    }
    cout << endl;
}

int main() {
    input();
    cal();
    return 0;
}

// 큰수 A+B
// 단순히 덧셈을 하면 되는 문제라고 생각되지만 A, B의 범위가 10의 10000승으로 10001자리까지 가능한 매우 큰 수이다.
// 해당 수를 덧셈하기 위해서는 문자 배열로 받아 이를 각각 더하고 다시 vector 안에 넣어 출력하는 것이 좋을 것으로 판단되었다.

// 실행시간  : 0ms