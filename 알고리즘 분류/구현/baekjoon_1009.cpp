#include <iostream>

using namespace std;


void input() {
	int a, b;
	cin >> a >> b;
	int num = 1;
	for (int i = 0; i < b; i++) {
		num *= a;
		num %= 10;
	}
	if (num == 0) num = 10;
	cout << num << "\n";

}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		input();
	}

	return 0;
}

// 1009 : 분산
// 컴퓨터가 10마다 데이터를 판단
// 마지막에 오는 컴퓨터가 계산하는 데이터가 몇인지 찾는 문제

// 실행시간 : 752ms