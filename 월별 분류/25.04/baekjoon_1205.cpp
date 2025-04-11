#include <iostream>
#include <stack>
#include <vector>


using namespace std;

int N, new_point, P;
stack<long long> st;

void input() {
	cin >> N >> new_point >> P;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		st.push(num);
	}
}

void cal() {

	bool check = true;

	while (!st.empty()) {
		int now = st.top();
		if (now < new_point) st.pop();
		else if (now == new_point) {
			int same_cnt = 0;
			int new_top = now;
			while (!st.empty() && st.top() == new_point) {
				same_cnt++;
				st.pop();
			}
			int cnt = st.size();

			if (cnt >= P) cout << -1 << "\n";
			else if (cnt + same_cnt >= P) cout << -1 << "\n";
			else cout << cnt + 1 << "\n";

			check = false;
			break;
		}
		else {
			int cnt = st.size();

			if (cnt >= P) cout << -1 << "\n";
			else  cout << cnt + 1 << "\n";

			check = false;
			break;
		}
	}

	if (check) cout << 1 << "\n";
}

int main() {

	input();
	cal();


	return 0;
}

// 백준 1205
// 스택


// 스택을 활용하여 앞의 값을 빼고 나머지 남은 크기를 활용하여 등수를 계산하면 끝나는 문제

// 실행시간 : 0ms