#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

char A[101];
char B[101];

void input() {
	cin >> A;
	cin >> B;
}

void Equals() {
	if (strcmp(A, "null") == 0) {
		cout << "NullPointerException\n";
	}
	else if (strcmp(A, B) != 0) cout << "false" << "\n";
	else cout << "true" << "\n";
}

void EqualsIgnore() {

	int len_a = strlen(A);
	int len_b = strlen(B);
	int gap = 'a' - 'A'; // 아스키코드의 차이
	bool check = true;

	if (strcmp(B, "null") == 0) check = false;
	else if (len_a != len_b) check = false;
	else {
		for (int i = 0; i < len_a; i++) {
			if (A[i] != B[i]) {
				int now_gap = (int)A[i] - (int)B[i];
				if (now_gap != gap && now_gap != (-1 * gap)) {
					check = false;
					break;
				}
			}
		}
	}

	if (strcmp(A, "null") == 0) {
		cout << "NullPointerException\n";
	}
	else if (check == false) cout << "false" << "\n";
	else cout << "true" << "\n";
}


int main() {

	input();
	Equals();
	EqualsIgnore();

	return 0;
}

// 백준 유틸컵 1번문제
// A, B의 입력 (A, B는 알파벳 대소문자와 숫자로 이루어진 문자열)을 받아 해당 문자열의 일치여부 (equal)와 대소문자 구분없는 일치여부를 확인하는 문제이다.
// null의 입력은 항상 객체로 인식되고 A가 입력될 시에는 NullPointerException을 출력해야한다. B는 객체 null이 들어와도 해당 동작을 안함 -> 따라서 B에 객체 null이 들어온 경우에는 false가 나와야됨
// null이 들어오는 것은 객체이기 때문에 B에 null이 들어오는 것도 객체로 들어오는 것이다. 따라서, equalsIgnore가 true로 동작하면 안된다.
// 해당 부분만 고려한다면 그렇게까지 어렵지 않은 문제.
// 항상 그렇지만 문제를 제대로 읽어 보도록 하자.

// 실행시간 : 0ms