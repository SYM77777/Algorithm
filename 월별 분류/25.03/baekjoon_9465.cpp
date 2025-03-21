#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v1;
vector<int> v2;
int ans = 0;


void input() {
	ans = 0;
	v1.clear();
	v2.clear();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v1.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v2.push_back(a);
	}
}

void cal() {
	
	for (int i = 0; i < N; i++) {

		int tmp1 = v1[i];
		int tmp2 = v2[i];

		if (max(v1[i], v2[i]) > ans) ans = max(v1[i], v2[i]);

		if (i - 1 < 0) continue;
		else {
			int check = tmp1 + v2[i - 1];
			int check_2 = tmp2 + v1[i - 1];

			if (check > v1[i]) v1[i] = check;
			if (check_2 > v2[i]) v2[i] = check_2;
		}

		if (max(v1[i], v2[i]) > ans) ans = max(v1[i], v2[i]);

		if (i - 2 < 0) continue;
		else {
			int check = tmp1 + v2[i - 2];
			int check_2 = tmp2 + v1[i - 2];

			if (check > v1[i]) v1[i] = check;
			if (check_2 > v2[i]) v2[i] = check_2;
		}

		if (max(v1[i], v2[i]) > ans) ans = max(v1[i], v2[i]);
		
	}

	cout << ans << "\n";
}

int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		input();
		cal();
	}


	return 0;
}

// DP 문제 : 스티커
// 스티커가 2N 만큼 2행 N열로 배치되어 있다. 스티커가 서로 변을 공유하는 곳은 망가지기 떄문에 더할 수 없다.
// 따라서, 아래와 같은 예시에서 만들어 질 수 있는 경우의 수는 다음과 같다.
// A B C  E 칸에 올 수 있는 최대값 경우의 수 : E(E가 제일 큼) / A+E (A와 E의 합합)
// D E F  C 칸에 올 수 있는 최대값 경우의 수 : C + E / C + A / C + D

// 즉, 처음 2열은 제일 큰 수가 정해져 있고 그 이후로는 n-2와 n-1의 합중 최대값을 찾는 문제이다.
// 따라서, 현재 지점을 0행 N이라고 할 때, 현재 지점까지에서 얻을 수 있는 최대값을 찾는 것이고 이는 n-2열의 0행 2행 값과 1행 n-1열의 합 중 최대값이다.
// 계속 진행하며 최대값을 찾아 출력하면 끝난다.

// 실행시간 : 248ms