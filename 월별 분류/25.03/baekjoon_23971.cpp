#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int H, W, N, M;

void input() {
	cin >> H >> W >> N >> M;
}


int main() {

	input();
	int col = (H - 1) / (N + 1);
	int row = (W - 1) / (M + 1);

	int ans = (col + 1) * (row + 1);

	cout << ans;

	return 0;
}

// ZOAC 4
// 강의실에 채울 수 있는 사람의 최댓값을 구하는 문제
// 가장 많이 채울 수 있는 방법은 처음부터 채우고 나머지 비비워야 하는 칸만큼 비워가며 행과 열 끝까지 최대로 채우는 방법이다.
// 해당 풀이는 위와 같다.
// 실행시간 : 0ms