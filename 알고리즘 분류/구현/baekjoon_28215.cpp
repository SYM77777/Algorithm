#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K;
int ans = 1e9;


vector<pair<int, int>> house;
deque<int> st;

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		house.push_back({ x, y });
	}
}

void cal() {
	int tmp = -1;
	int check[51] = { 0, };

	for (int i = 0; i < N; i++) check[i] = 1e9;

	for (int i = 0; i < K; i++) check[st[i]] = -1;

	for (int i = 0; i < K; i++) {
		int now = st[i];
		int now_x = house[now].first;
		int now_y = house[now].second;

		for (int j = 0; j < N; j++) {
			if (check[j] == -1) continue;
			else {
				int next_x = house[j].first;
				int next_y = house[j].second;

				if ((abs(now_x - next_x) + abs(now_y - next_y)) < check[j]) check[j] = (abs(now_x - next_x) + abs(now_y - next_y));
			}
		}
	}

	// check에 있는 요소 중 가장 큰 값 찾기
	for (int i = 0; i < N; i++) {
		if (check[i] != -1 && check[i] > tmp) tmp = check[i];
	}

	// ans는 둘 중 더 작은값이다.
	if (tmp != -1) ans = min(ans, tmp);
	else ans = 0;
}

void DFS(int d, int cnt) {

	if (cnt == K) { // 만약 다 골랐다면
		cal();
		return;
	}

	for (int i = d; i < N; i++) {
		st.push_back(i); // 골랐음
		DFS(i + 1, cnt + 1); // 모든 경우의 수 체크
		st.pop_back(); // 이제 뺀다
	}

}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	DFS(0, 0);

	cout << ans << "\n";

	return 0;
}

// 백준 28215 : 대피소
// 구현, 브루트포스 알고리즘, DFS

// 해당 문제는 N = 50, K = 3이므로 완전탐색이 충분히 가능하다고 생각되었다.

// 결국, 완전 탐색으로 가능하긴 했는데 오류가 나왔던 코드는 만약 집의 갯수와 대피소의 수가 같은 경우에서 오류가 발생하였다.
// 만약, 둘이 같은 경우 나는 tmp = -1로 설정되어 실제로 계산되어야 하는 0과는 다른 값이 튀어나올 수 있다.
// 따라서, if문을 추가하여 이를 해결하였다. 실제 시험에서도 분명 완전 탐색 관련 문제가 나올 수 있으므로 만약 완전탐색이 가능하다면 모든 경우의 수를 디버깅 해보는 것이 중요할 것으로 생각된다.

// 실행시간 : 12ms