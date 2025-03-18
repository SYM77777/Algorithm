#include <iostream>

using namespace std;

int N, R;
int cnt = 0;
int dp[10001] = { 0, };

void input() {
	cin >> N >> R;
	for (int i = 0; i < R; i++) {
		int num;
		cin >> num;
		dp[num] = 1;
	}
}

void cal() {
	for (int i = 1; i <= N; i++) {
		if (dp[i] == 0) {
			cout << i << " ";
			cnt++;
		}
	}
	if (cnt == 0) cout << "*";
}

int main() {

	input();
	cal();
	return 0;
}

// 13627 : Dangerous Dive
// 지진이 난 지역에 자원봉사를 간 사람의 수가 있고 돌아온 사람이 주어지면 안돌아온사람을 확인하는 코드를 제작하는 것이다.
// dp로 배열을 하나 만들어 돌아온 사람의 index를 체크하고 나중에 한번만 for문으로 체크하면 종료
// 이 코드가 가능한 이유는 자원 봉사의 최대값이 10000이기 떄문에 최대 반복문 20000번 반복하고 끝이기 때문이다.

// 실행시간 : 0ms