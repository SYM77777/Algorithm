#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int T;
string INS;
int error = 0;
bool state = true;

deque<int> dq;


void init() {
	error = 0;
	state = true;
}


int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {

		init();

		int num;
		string arr;
		

		cin >> INS;
		cin >> num;
		cin >> arr;

		int now = -1;

		for (int i = 0; i < arr.length(); i++) {
			if (arr[i] >= '0' && arr[i] <= '9') {
				if (now == -1) now += (int)(arr[i] - '0') + 1;
				else {
					now *= 10;
					now += (int)(arr[i] - '0');
				}
			}
			else if (arr[i] == ',' || arr[i] == ']') {
				if (now == -1) continue;
				else dq.push_back(now);
				now = -1;
			}
		}

		
		for (int i = 0; i < INS.length(); i++) {

			if (INS[i] == 'R') {
				if (state) state = false;
				else state = true;

			}
			else if (INS[i] == 'D') {
				if (dq.size() == 0) {
					cout << "error\n";
					error = 1;
					break;
				}
				else {
					if (state) dq.pop_front();
					else dq.pop_back();
				}
			}
			else {
				cout << "error\n";
				error = 1;
				break;
			}
		}

		if (!state) {
			deque<int> dq2;
			for (int i = (dq.size() - 1); i >= 0; i--) {

				dq2.push_back(dq[i]);
			}
			dq = dq2;
		}

		if (error == 1) continue;
		else {
			cout << "[";
			while (!dq.empty()) {
				if (dq.size() == 1) cout << dq.front();
				else cout << dq.front() << ",";
				dq.pop_front();
			}
			cout << "]\n";
		}

	}



	return 0;
}

// deque를 사용하면 간단하게 풀리는 되게 쉬운 문제
// 여기서 가장 주의해야할 부분은 R에 해당하는 전체 배열을 뒤집는 부분이다.
// 최대 크기가 10만이기 때문에 이를 많이 반복하면 시간초과가 나올 수 밖에 없다
// 따라서 R에 따라 뒤집은 상황을 판단하고 deque의 장점인 양방향 입출을 사용하여 양방향으로 삭제하는 것이 가장 중요한 부분이다.
// 그것을 제외하면 매우 쉬운 문제였다.