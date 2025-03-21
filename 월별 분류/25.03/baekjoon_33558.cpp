#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int U, V;
char msg[20];
char map[201][201];
char part[201][201];
char mirror[401][401]; // 0 : 1사분면, 1: 2사분면, 2 : 3사분면, 3 : 4사분면


void input() {

	cin >> N >> M;
	cin >> U >> V;
	for (int i = 0; i < U; i++) {
		for (int j = 0; j < V; j++) {
			cin >> part[i][j];
			map[i][j] = part[i][j];
			mirror[i][j] = part[i][j];
			mirror[i][(2 * V) - j - 1] = part[i][j];
			mirror[(2 * U) - 1 - i][(2 * V) - j - 1] = part[i][j];
			mirror[(2 * U) - 1 - i][j] = part[i][j];
		}
	}
	cin >> msg;
}

void cal() {

	if (strcmp(msg, "clamp-to-edge") == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i < U) {
					if (j < V) continue;
					else map[i][j] = part[i][V - 1];
				}
				else {
					if (j < V) map[i][j] = part[U -1][j];
					else map[i][j] = part[U - 1][V - 1];
				}
			}
		}
	}
	else if (strcmp(msg, "repeat") == 0) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = part[i % U][j % V];
			}
		}
	}
	else if (strcmp(msg, "mirrored-repeat") == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = mirror[i % (2 * U)][j % (2 * V)];
			}
		}
	}


}

void ans() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}

int main() {

	input();
	cal();
	ans();

	return 0;
}

// 백준 유틸컵 3번문제
// 명령어를 입력받은거에 따른 평면 채우기 문제이다.
// 3가지 명령이 존재하고 해당 명령에 따른 동작을 구현하는 것이다.
// 유의해야 할 점은 배열이 띄어쓰기가 없기 떄문에 문자열로 받는것과 mirror 동작을 할 때 실행시간 단축을 위하여 배열을 2배로 늘려 (U, V의 최대값이 200이기 때문에 400으로 늘려도 충분히 가능) 저장
// 실행시간 : 4ms