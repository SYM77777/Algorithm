#include <iostream>
#include <vector>

using namespace std;

int N;
long long A;
long long B;

void cal() {
	cin >> A >> B;
	if (B > A) {
		long long tmp = A;
		A = B;
		B = tmp;
	}
	if (A == 1 || B == 1) {
		cout << 1 << "\n";
	}
	else {
		// 실제 곱셈값
		long long total = A * B;

		// 가라 곱셈 값
		vector<int> v_a;
		vector<int> v_b;

		while ((A != 0) || (B != 0)) {
			if (A != 0) {
				if (B != 0) {
					v_a.push_back(A % 10);
					v_b.push_back(B % 10);
					A = A / 10;
					B = B / 10;
				}
				else {
					v_a.push_back(A % 10);
					A = A / 10;
				}
			}
			else {
				if (B != 0) {
					v_b.push_back(B % 10);
					B = B / 10;
				}
			}
		}
		bool check = true;
		int gap = v_a.size() - v_b.size();
		long long new_cal = 0; // 최종 가라 곱셈 값
		long long A_left_1 = 1; // 1차 가라 곱셈 작업 결과

		// 계산작업 1차
		for (int i = v_b.size() - 1; i >= 0; i--) {
			if (v_b[i] * v_a[i] < 10) {
				new_cal *= 10;
				A_left_1 *= 10;
			}
			else {
				new_cal *= 100;
				A_left_1 *= 100;
			}
			new_cal += v_b[i] * v_a[i];

		}

		// 내리는 작업
		long long new_a = 0;
		int gap_b = 1;
		while (gap_b <= gap) {
			new_a *= 10;
			new_a += v_a[v_a.size() - gap_b];
			gap_b++;
		}
		new_cal += (new_a * A_left_1);
		if (total != new_cal) check = false;

		if (check) cout << 1 << "\n";
		else cout << 0 << "\n";
		


	}


}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cal();
	}


	return 0;
}

// 유틸컵 2번문제 (33557번)
// 잘못된 계산법과 맞는 계산법의 값이 서로 일치하는 지 확인하는 문제이다.
// 해당 문제는 구현이 100%이므로 열심히 구현을 하면 된다.

// 다른 풀이로는 실제 계산이 아닌 문자열로 받아 문자열을 concat하는 방식으로 붙이면 된다고 한다.

// 실행시간 : 0ms