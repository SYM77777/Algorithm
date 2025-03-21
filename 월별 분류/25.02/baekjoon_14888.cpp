#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int arr[12] = { 0, };
int cal[4] = { 0, };
int visited[4] = { 0, };
long long max_ans = -1e18;
long long min_ans = 1e18;


struct equation {
	int plus;
	int minus;
	int mul;
	int div;
};

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> cal[i];
	}
}

void DFS(int num, int now_cal) {

	if (num == N) {
		if (now_cal > max_ans) max_ans = now_cal;
		if (now_cal < min_ans) min_ans = now_cal;

		return;
	}

	int new_cal = now_cal;

	for (int i = 0; i < 4; i++) {


		if ((visited[i] + 1) > cal[i]) continue;
		int tmp = new_cal;

		if (i == 0) new_cal += arr[num];
		else if (i == 1) new_cal -= arr[num];
		else if (i == 2) new_cal *= arr[num];
		else if (i == 3) new_cal /= arr[num];

		num++;
		visited[i]++;
		DFS(num, new_cal);
		new_cal = tmp;
		num--;
		visited[i]--;
	}
}


int main() {

	input();
	DFS(1, arr[0]);

	cout << max_ans << "\n" << min_ans;

	return 0;
}

// 연산자 끼워넣기
// 해당 문제는 숫자와 사칙연산 기호의 개수를 제공하고 해당 조합으로 만들 수 있는 가장 큰 수와 가장 작은 수의 결과값을 출력하는 문제이다.
// 해당 문제의 해결방법으로 DFS를 활용하여 모든 수의 합을 계산하여 최댓값, 최솟값이 계산될 때 마다 해당 값을 갱신해주는 것이다.
// 계산식이 10억을 넘어갈 수 있기 떄문에 정답의 자료형을 주의하여 long long으로 두었습니다.

// 실행시간 0ms
// 다만 다른 코드의 메모리가 더 적었기 때문에 최적화 코드는 한번 더 살펴보기로 하자.