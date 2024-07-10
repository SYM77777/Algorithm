#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

string s;

deque<char> dq;

int ANS = 0;

void input() {

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		dq.push_back(s[i]);
	}

}

void ans() {
	
	int CNT = 0;
	int num;
	int check = 0;

	while (!dq.empty()) {


		char now = dq.back();
		dq.pop_back();

		if (check == 1) {
			num = (int)(now - '0');
			ANS *= num;
			check = 0;
		}
		else {
			if (now == ')') {
				CNT++;
			}
			else if (now == '(') {
				CNT--;
				check = 1;
			}
			else {
				ANS++;
			}
		}
	}
}

int main() {

	input();
	ans();

	cout << ANS << "\n";

	return 0;
}

// 문자열 압축을 해제하여 해당 문자열의 길이를 알아보는 문제이다.
// 여기서의 핵심은 결국 문제에서 요구하는 것은 문자열의 길이만이기 떄문에 어떤 문자열인지는 중요하지 않다.
// 따라서, (, ) 와 해당 그 사이에 존재하는 숫자가 어떤것인지만 확인하고 그 길이에 따라 현재 값에 곱해주면 끝
// 따라서 뒤에서부터 해당 값을 찾고 문자열을 반복하기 위해서는 deque 혹은 vector를 사용하는 것이 좋고 나는 deque를 사용하였다.
// 1. )의 시작점을 찾는다
// 2. 그 사이의 값을 알아본다.
// 3. ( 로 닫히면 그 사이의 길이를 앞의 숫자랑 곱해주기 위하여 check = 1로 변환
// 4. 다시 숫자가 나오면 ANS 길이에 더해주고 만약 (가 다시 나오면 다시 곱해줄 준비
// 위 과정을 반복하면 원하는 문자열의 길이를 구할 수 있다.