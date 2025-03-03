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
// 명령어의 
// null이 들어오는 것은 객체이기 때문에 B에 null이 들어오는 것도 객체로 들어오는 것이다. 따라서, equalsIgnore가 true로 동작하면 안된다.