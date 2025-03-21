#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[20][20];
int ans = 0;


void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > ans) ans = arr[i][j];
		}
	}
}

void Move(int num) {

	deque<int> q[20];

	// 차례대로 동서남북으로 진행
	if (num == 0){ // 동
		for (int i = 0; i < N; i++) {
			int check = 0;
			for (int j = N - 1; j >= 0; j--) {
				if (arr[i][j] != 0) {
					if (check != 0) {
						if (arr[i][j] == check) {
							q[i].push_back(check + check);
							if (ans < 2 * check) ans = 2 * check;
							check = 0;
						}
						else {
							q[i].push_back(check);
							check = arr[i][j];
						}
					}
					else check = arr[i][j];
				}
				else continue;
			}
			if (check != 0) q[i].push_back(check);
		}

		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (q[i].empty()) arr[i][j] = 0;
				else {
					arr[i][j] = q[i].front();
					q[i].pop_front();
				}
			}
		}
	}
	else if (num == 1) { // 서
		for (int i = 0; i < N; i++) {
			int check = 0;
			for (int j = 0; j < N; j++) {
				if (arr[i][j] != 0) {
					if (check != 0) {
						if (arr[i][j] == check) {
							q[i].push_back(check + check);
							if (ans < 2 * check) ans = 2 * check;
							check = 0;
						}
						else {
							q[i].push_back(check);
							check = arr[i][j];
						}
					}
					else check = arr[i][j];
				}
				else continue;
			}
			if (check != 0) q[i].push_back(check);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (q[i].empty()) arr[i][j] = 0;
				else {
					arr[i][j] = q[i].front();
					q[i].pop_front();
				}
			}
		}
	}
	else if (num == 2) { // 남
		for (int i = 0; i < N; i++) {
			int check = 0;
			for (int j = N - 1; j >= 0; j--) {
				if (arr[j][i] != 0) {
					if (check != 0) {
						if (arr[j][i] == check) {
							q[i].push_back(check + check);
							if (ans < 2 * check) ans = 2 * check;
							check = 0;
						}
						else {
							q[i].push_back(check);
							check = arr[j][i];
						}
					}
					else check = arr[j][i];
				}
				else continue;
			}
			if (check != 0) q[i].push_back(check);
		}

		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (q[i].empty()) arr[j][i] = 0;
				else {
					arr[j][i] = q[i].front();
					q[i].pop_front();
				}
			}
		}
	}
	else if (num == 3) { // 북
		for (int i = 0; i < N; i++) {
			int check = 0;
			for (int j = 0; j < N; j++) {
				if (arr[j][i] != 0) {
					if (check != 0) {
						if (arr[j][i] == check) {
							q[i].push_back(check + check);
							if (ans < 2 * check) ans = 2 * check;
							check = 0;
						}
						else {
							q[i].push_back(check);
							check = arr[j][i];
						}
					}
					else check = arr[j][i];
				}
				else continue;
			}
			if (check != 0) q[i].push_back(check);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (q[i].empty()) arr[j][i] = 0;
				else {
					arr[j][i] = q[i].front();
					q[i].pop_front();
				}
			}
		}
	}

	// 최대값이 나온 경우 이를 ans 값으로 넣는다.

}

void DFS(int turn) {
	if (turn == 5) return;

	int tmp[20][20] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {

		
		Move(i);

		DFS(turn + 1);
		// 다시 원상복구
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = tmp[i][j];
			}
		}


	}
}

int main() {

	input();
	DFS(0);
	cout << ans;
	return 0;
}

// 2048 문제로 5번 움직여 나올 수 있는 최대 숫자를 찾는 문제이다.
// 해당 문제의 핵심은 얼마나 빨리 해당 문제를 해결할 수 있는가 라고 생각된다.
// 1. 현재 풀이 방법 : DFS (깊이 우선 탐색)
// - 처음 배열의 입력을 받으며 가장 큰값을 찾는다.
// - 동, 서, 남, 북으로 움직였을 떄 한쪽으로 쏠리는 것과 합쳐지는 것을 queue로 구현