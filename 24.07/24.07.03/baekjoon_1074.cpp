#include <iostream>

using namespace std;

long long N, r, c;
long long arr[4][4] = { {0, 1, 4, 5}, {2, 3, 6, 7}, {8, 9, 12, 13}, {10, 11, 14, 15} };
long long Ans = 0;


void Init() {
    cin >> N >> r >> c;

}

void ans(int N, int r, int c) {

    if (N <= 2) {
        Ans += arr[r][c];
        cout << Ans;
    }
    else {

        long long len = 1;
        len = len << N - 1;
        // 몇 사분면인지 체크
        // 4
        if (r >= len && c >= len) {
            Ans += 3 * (len * len);
            r -= len;
            c -= len;

        }
        // 3
        else if (r >= len && c < len) {
            Ans += 2 * (len * len);
            r -= len;
        }
        // 2
        else if (r < len && c >= len) {
            Ans += (len * len);
            c -= len;
        }
        // 1은 생략


        ans(N - 1, r, c);

    }
  
}

int main() {

    Init();
    ans(N, r, c);

    return 0;
}


// 일반 반복문과 재귀함수를 사용했을때의 시간차이 -- 유효했던 차이
// if문 안의 비교조건의 개수
// 
// 
// 처음에는 위의 코드에서 while문을 사용하여 반복문을 작성하였다.
// 하지만 시간초과가 나왔고 while문을 삭제하고 이를 재귀함수로 작성하여 실행하니 성공하였다.
// 문제 해결중
//