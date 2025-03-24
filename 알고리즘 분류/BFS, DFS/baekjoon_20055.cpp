#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int N, K;
deque<int> dur;
int level = 0;
int check = 0;

void input() {
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) {
		int num;
		cin >> num;
		dur.push_back(num);
	}
}

void BFS() {

	bool fin = false;
	deque<int> robot;

	while (!fin) {

		level++;

		// 벨트 회전 (로봇도 올려져 있으면 같이 회전)
		int now_dur = dur.back();
		dur.pop_back();
		dur.push_front(now_dur);

		int cnt = robot.size();
		for (int i = 0; i < cnt; i++) {
			int next_place = robot.front() + 1;
			robot.pop_front();

			// 로봇의 회전
			if (next_place < N - 1) { // 이후 로봇의 이동여부 확인
				int move_robot = next_place + 1;
				if (dur[move_robot] == 0) { // 내구도가 모자람
					robot.push_back(next_place); // 회전만 한다.
				}
				else if (robot.size() != 0 && robot.back() == move_robot) robot.push_back(next_place); // 이미 다른 로봇이 있음 -> 회전만 한다.
				else {
					dur[move_robot] -= 1; // 갈 수도 있고 내구도도 충분함 : 이동
					if (dur[move_robot] == 0) check++;
					if (move_robot != N - 1) robot.push_back(move_robot); // 만약 로봇이 이동한 위치가 내려놓는 위치면 로봇을 넣을 필요는 없음
				}
			}

		}

		// 로봇 올림
		if (dur[0] != 0) {
			dur[0] -= 1;
			robot.push_back(0);
			if (dur[0] == 0) check++;
		}

			// 동작 종료 확인
		if (check >= K) fin = true;

	}

}


int main() {

	input();
	BFS();

	cout << level << "\n";

	return 0;
}

// 백준 20055번 : 컨베이어 벨트 위의 로봇
// 해당 문제는 정해진 규칙을 차례대로 실행하여 내구도의 크기가 0이 되는 갯수가 일정 수치를 넘어가면 종료하고 종료한 단계가 몇단계인지 확인하는 문제이다.
// 해당 문제의 핵심은 벨트가 회전하며 로봇이 같이 회전하고 그 후, 로봇이 이동하는 것이다.
// 즉, 벨트의 회전에서 모든 요소를 회전시킬 것인지, 아님 포인터의 값만으로 현재 위치를 판단할 것인지 이다.
// 나는 전자로 해결하여 deque를 사용하였고 회전할때마다 내구도의 위치를 옮겼다. (맨 뒤의 요소를 맨 앞으로 옮겨 구현)
// 그러나, 해당 방법은 구현에서 최적화라고 보기 어려운것이 요소를 빼고 넣고 하는 일련의 동작으로 시간 최적화 부분에서 문제가 발생할 수도 있다.
// 따라서, 이때 포인터를 사용하여 start, end로 해당 위치를 바꿔가며 내구도를 처리한다면 시간복잡도를 줄일수 있을 것이다.
// 
// ※ 시간 복잡도 측면
// 둘다 O(1)이지만 deque는 STL 구조체라 내부 오버헤드가 있고 매번 요소 삽입/삭제하면서 참조/복사 비용이 발생하는 문제가 발생한다.
// 또한, 추가적인 조건 처리가 필요하여 시간이 더 필요할 수 있다. (push 예외 처리 or 경계 조건 처리 등등)

// 실행시간 : 52ms

// 아래 코드는 해당 문제의 최적화된 코드이다.
// 기본적인 방법은 위와 동일하지만 내구도의 위치를 회전하는 과정을 포인터로 구현하였다.

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int N, K;
//int a[210]; //내구도
//int chk[210]; //로봇 있는지 체크
//int input = -1, output = -1;
//int cnt = 0;
//int start = 1, end;
//struct convey {
//	int pos;
//}c[110];
//
//void move();
//void push();
//
//int main(void) {
//	int i, time = 0;
//	scanf("%d%d", &N, &K); //N은 컨베이어 벨트 //K는 한계
//	end = N;
//	for (i = 1; i <= 2 * N; i++)
//		scanf("%d", &a[i]);
//	while (cnt < K) {
//		output = -1;
//		time++;
//		start--; if (start == 0) start = 2 * N;
//		end--; if (end == 0) end = 2 * N; //한 칸 회전
//		if (c[output + 1].pos == end) {
//			c[++output].pos = 0;
//			chk[end] = 0;
//		}
//		move();
//		if (chk[start] == 0 && a[start] != 0) { //올라가는 위치에 로봇 올린다
//			chk[start] = 1;
//			c[++input].pos = start;
//			a[start]--;
//			if (a[start] == 0)
//				cnt++;
//		}
//		push();
//	}
//	printf("%d", time);
//	return 0;
//}
//
//void move() {
//	int tx;
//	while (input != output) {
//		++output;
//		tx = c[output].pos + 1; if (tx == 2 * N + 1) tx = 1;
//		if (chk[tx] == 0 && a[tx] != 0) { //로봇없고 칸의 내구도 1 이상 남아 있다
//			chk[c[output].pos] = 0; //원래꺼 체크 없애고
//			c[output].pos = tx; //한 칸 전진
//			chk[tx] = 1;
//			a[tx]--; //내구도 한 칸 단다
//			if (a[tx] == 0)
//				cnt++;
//			if (tx == end) { //내려야 한다
//				c[output].pos = 0;
//				chk[end] = 0;
//			}
//		}
//	}
//	return;
//}
//
//void push() {
//	int i, j;
//	for (i = 0; i < N; i++) {
//		if (c[i].pos != 0)
//			break;
//	}
//	if (i == 0) return; //밀 필요 없을때
//	j = -1;
//	for (; i <= input; i++) {
//		c[++j].pos = c[i].pos;
//		c[i].pos = 0;
//	}
//	input = j;
//	return;
//}