#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<bool> v(101);

int stu;

void cal(int S, int num) {

	if (S == 1) {
		for (int i = 1; i <= N; i++) {
			if (num * i > N) break;
			else v[num * i] = !v[num * i];
		}
	}
	else {
		v[num] = !v[num];
		int left = num - 1;
		int right = num + 1;
		while (left > 0 && right <= N) {
			if (v[left] == v[right]) {
				v[right] = !v[right];
				v[left] = !v[left];
				left -= 1;
				right += 1;
			}
			else break;
		}

	}

}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		if (num == 1) v[i] = true;
		else v[i] = false;
	}

	cin >> stu;
	for (int i = 0; i < stu; i++) {
		int S, num;
		cin >> S >> num;
		cal(S, num);
	}

	for (int i = 1; i <= N; i++) {
		if (v[i]) cout << 1 << " ";
		else cout << 0 << " ";
		if (i % 20 == 0) cout << "\n";
	}
}




int main() {

	input();

	return 0;
}

// 백준 1244번 : 스위치 켜고 끄기
// 구현 문제

// 좌 우의 합을 더하여 계산하는 비슷한 문제이다. (좀 더 많이 쉬운 버전)
// 문제의 핵심은 출력 방식을 제대로 읽는 것이다.

// 그 이외에는 구현을 하면 매우 간단했던 문제이다.


// 실행시간 : 0ms