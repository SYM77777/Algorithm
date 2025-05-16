#include <iostream>
#include <string>
#include <queue>

using namespace std;

string s;
deque<string> dq;
int zero_cnt = 0;

void input() {

	cin >> s;

	int now = 0;
	string tmp = "";
	bool check = false;
	bool zero_check = false;
	while (now < s.size()) {

		if (s[now] == ':') {
			if (tmp == "") {
				if (now == 0) { // 시작하자마자 0이 연속되어 나와 이를 처리하는 경우
					dq.push_back("");
					now += 1;
				}
				else { // 시작하자마자는 아닌데 중간에 나와 이를 처리하는 경우
					dq.push_back("");
				}
				zero_check = true;
			}
			else {
				dq.push_back(tmp);
				tmp = "";
				check = false;
			}
		}
		else {
			tmp += s[now];
			check = true;
		}

		if (now == s.size() - 1 && check) {
			dq.push_back(tmp);
			break;
		}
		now++;
	}

	if (zero_check) zero_cnt = 9 - dq.size();
}

void cal() {

	for (int i = 0; i < dq.size(); i++) {

		string now = dq[i];
		string ans = "";

		if (now == "") {
			for (int j = 0; j < zero_cnt; j++) {
				cout << "0000";

				if (j != zero_cnt - 1) cout << ":";
			}
			if (i != dq.size() - 1) cout << ":";
		}
		else {
			if (now.size() < 4) {
				for (int i = 0; i < 4 - now.size(); i++) {
					ans += '0';
				}
			}
			ans += now;

			cout << ans;
			if (i != dq.size() - 1) cout << ":";
		}

	}


}


int main() {


	input();
	cal();


	return 0;


}

// 백준 3107 : IPv6
// 문자열, 구현

// 해당 문제는 문자열을 입력을 받고 IPv6를 구성하는 방법을 통해 실제 IPv6는 어떤 문자열을 가지고 있을지 알아보는 문제이다.
// 해당 문제의 핵심 포인트는 생략된 부분을 어떻게 처리하는가 이다.
// 문제의 조건에 의하면 0으로 연속된 부분이 나온다면 어느곳에서든 :: 로 1번 생략 가능하다는 것이다.
// 따라서, 이를 확인하기 위하여 나는 코드에서 해당 생략이 발생한 위치와 발생된 크기를 확인하였고 이를 통해 실제로 복원하는 과정에서 생략된 횟수만큼 0000을 반복하도록 코드를 작성하였다.

// 조건을 제대로 확인하였다면 구현은 생각보다 그리 어렵지는 않았던 문제

// 실행시간 : 0ms